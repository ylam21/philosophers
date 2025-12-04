/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:47:42 by omaly             #+#    #+#             */
/*   Updated: 2025/12/04 23:38:54 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_all_full(t_philo *philos, size_t count)
{
	size_t	i;
	int		limit;
	int		meals_eaten;

	limit = philos[0].data->total_meals;
	i = 0;
	while (i < count)
	{
		meals_eaten = read_lock(&philos[i].meals_eaten, &philos[i].meal_lock);
		if (meals_eaten != limit)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_starvation(t_philo *philos, size_t count, int *died)
{
	size_t	i;
	long	time_since_meal;

	i = 0;
	while (i < count)
	{
		pthread_mutex_lock(&philos[i].meal_lock);
		time_since_meal = get_time() - philos[i].last_meal_time;
		pthread_mutex_unlock(&philos[i].meal_lock);
		if (time_since_meal > philos[i].data->time_to_die)
		{
			pthread_mutex_lock(philos[i].write_lock);
			printf("%ld %d died\n", get_time() - philos[i].data->start_time,
				philos[i].id);
			write_lock(philos[i].stop_flag, philos[i].stop_lock, 1);
			pthread_mutex_unlock(philos[i].write_lock);
			*died = 1;
			break ;
		}
		i++;
	}
}

void	monitor(t_philo *philos, size_t count)
{
	int	someone_died;

	someone_died = 0;
	while (someone_died == 0)
	{
		check_starvation(philos, count, &someone_died);
		if (philos->data->total_meals != -1 && check_all_full(philos, count) == 1)
		{
			write_lock(philos->stop_flag, philos->stop_lock, 1);
			break ;
		}
	}
}

int	run_simulation(pthread_t *threads, t_philo *philos, size_t count)
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
	monitor(philos, count);
	i = 0;
	while (i < count)
	{
		if (pthread_join(threads[i], NULL) != 0)
			return (3);
		i++;
	}
	return (0);
}
