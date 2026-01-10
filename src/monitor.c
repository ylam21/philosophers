/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:47:42 by omaly             #+#    #+#             */
/*   Updated: 2026/01/07 18:48:53 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_meals(t_philo *philos, pthread_mutex_t *meal_locks, t_data *data)
{
	size_t	i;
	int	limit;
	int	meals_eaten;

	limit = data->total_meals;
	i = 0;
	while (i < data->philo_count)
	{
		meals_eaten = read_flag(&philos[i].meals_eaten, &meal_locks[i]);
		if (meals_eaten < limit)
			return ;
		i++;
	}
	write_flag(&data->stop_flag, &data->stop_lock, 1);
	return ;
}

void	check_starvation(t_philo *philos, pthread_mutex_t *meal_locks, t_data *data)
{
	size_t		i;
	long	time_since_meal;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_lock(&meal_locks[i]);
		time_since_meal = get_timestamp_millisec() - philos[i].last_meal_time;
		pthread_mutex_unlock(&meal_locks[i]);
		if (time_since_meal > data->time_to_die)
		{
			write_flag(&data->stop_flag, &data->stop_lock, 1);
			write_death(&philos[i], data);
			break ;
		}
		i++;
	}
}

void	monitor_default(t_philo *philos, pthread_mutex_t *meal_locks, t_data *data)
{
	while (1)
	{
		check_starvation(philos, meal_locks, data);
		if (read_flag(&data->stop_flag, &data->stop_lock) == 1)
			break ;
		usleep(1000);
	}
}

void	monitor_with_meals(t_philo *philos, pthread_mutex_t *meal_locks, t_data *data)
{
	while (1)
	{
		check_starvation(philos, meal_locks, data);
		if (read_flag(&data->stop_flag, &data->stop_lock) == 1)
			break ;
		check_meals(philos, meal_locks, data);
		if (read_flag(&data->stop_flag, &data->stop_lock) == 1)
			break ;
		usleep(1000);
	}
}

void	monitor(t_philo *philos, pthread_mutex_t *meal_locks, t_data *data)
{
	int	meal_limit_set;

	meal_limit_set = data->total_meals != -1;
	if (meal_limit_set)
		monitor_with_meals(philos, meal_locks, data);
	else
		monitor_default(philos, meal_locks, data);
	return ;
}
