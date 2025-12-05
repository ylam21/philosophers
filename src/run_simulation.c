/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:47:42 by omaly             #+#    #+#             */
/*   Updated: 2025/12/05 13:27:43 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_meals(t_philo *philos, t_data *data)
{
	int	i;
	int	limit;
	int	meals_eaten;

	limit = data->total_meals;
	i = 0;
	while (i < data->philo_count)
	{
		meals_eaten = read_flag(&philos->meals_eaten, &data->meal_lock);
		if (meals_eaten < limit)
			return ;
		i++;
	}
	write_flag(&data->stop_flag, &data->stop_lock, 1);
	return ;
}

void	check_starvation(t_philo *philos, t_data *data)
{
	int		i;
	long	time_since_meal;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_lock(&data->meal_lock);
		time_since_meal = get_time() - philos[i].last_meal_time;
		pthread_mutex_unlock(&data->meal_lock);
		if (time_since_meal > data->time_to_die)
		{
			write_flag(&data->stop_flag, &data->stop_lock, 1);
			pthread_mutex_lock(&data->write_lock);
			printf("%ld %d died\n", get_time() - data->start_time,
				philos[i].id);
			pthread_mutex_unlock(&data->write_lock);
			break ;
		}
		i++;
	}
}

void	monitor_default(t_philo *philos, t_data *data)
{
	while (1)
	{
		check_starvation(philos, data);
		if (read_flag(&data->stop_flag, &data->stop_lock) == 1)
			break ;
	}
}

void	monitor_with_meals(t_philo *philos, t_data *data)
{
	while (1)
	{
		check_starvation(philos, data);
		if (read_flag(&data->stop_flag, &data->stop_lock) == 1)
			break ;
		check_meals(philos, data);
		if (read_flag(&data->stop_flag, &data->stop_lock) == 1)
			break ;
	}
}

int	run_simulation(pthread_t *threads, t_philo *philos, t_data *data)
{
	int	i;
	int	meal_limit_set;

	meal_limit_set = data->total_meals != -1;
	data->start_time = get_time();
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_create(&threads[i], NULL, &routine, &philos[i]) != 0)
			return (1);
		i++;
	}
	if (meal_limit_set)
		monitor_with_meals(philos, data);
	else
		monitor_default(philos, data);
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_join(threads[i], NULL) != 0)
			return (2);
		i++;
	}
	return (0);
}
