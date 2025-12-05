/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:47:42 by omaly             #+#    #+#             */
/*   Updated: 2025/12/05 12:30:30 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_all_full(t_philo *philos, t_data *data, size_t count)
{
	size_t	i;
	int		limit;
	int		meals_eaten;

	limit = philos[0].data->total_meals;
	if (limit == -1)
		return (0);
	i = 0;
	while (i < count)
	{
		meals_eaten = read_lock(&philos->meals_eaten, &data->meal_lock);
		if (meals_eaten < limit)
			return (0);
		i++;
	}
	return (1);
}

void	check_starvation(t_philo *philos, t_data *data, size_t count)
{
	size_t	i;
	long	time_since_meal;

	i = 0;
	while (i < count)
	{
		pthread_mutex_lock(&data->meal_lock);
		time_since_meal = get_time() - philos[i].last_meal_time;
		pthread_mutex_unlock(&data->meal_lock);
		if (time_since_meal > data->time_to_die)
		{
			pthread_mutex_lock(&data->write_lock);
			printf("%ld %d died\n", get_time() - data->start_time,
				philos[i].id);
			write_lock(&data->stop_flag, &data->stop_lock, 1);
			pthread_mutex_unlock(&data->write_lock);
			break ;
		}
		i++;
	}
}

void	monitor(t_philo *philos, t_data *data, size_t count)
{
	while (read_lock(&data->stop_flag, &data->stop_lock) == 0)
	{
		check_starvation(philos, data, count);
		if (read_lock(&data->stop_flag, &data->stop_lock) == 1)
			break ;
		if (data->total_meals != -1 && check_all_full(philos, data, count) == 1)
		{
			write_lock(&data->stop_flag, &data->stop_lock, 1);
			break ;
		}
		usleep(1000);
	}
}

int	run_simulation(pthread_t *threads, t_philo *philos, t_data *data,
		size_t count)
{
	size_t	i;

	if (threads == NULL || philos == NULL)
		return (1);
	i = 0;
	while (i < count)
	{
		if (pthread_create(&threads[i], NULL, &routine, &philos[i]) != 0)
			return (2);
		i++;
	}
	monitor(philos, data, count);
	i = 0;
	while (i < count)
	{
		if (pthread_join(threads[i], NULL) != 0)
			return (3);
		i++;
	}
	return (0);
}
