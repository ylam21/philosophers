/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:03:14 by omaly             #+#    #+#             */
/*   Updated: 2026/02/16 20:23:20 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine_single(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal_time = get_timestamp_millisec();
	pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_lock(&philo->left_fork->fork_lock);
	change_fork_status(&philo->left_fork->fork_status, FORK_TAKEN);
	write_status(philo, data, "has taken a fork");
	usleep(data->time_to_die * 1000);
	change_fork_status(&philo->left_fork->fork_status, FORK_RELEASED);
	pthread_mutex_unlock(&philo->left_fork->fork_lock);
	return (NULL);
}

void	*routine_even(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal_time = get_timestamp_millisec();
	pthread_mutex_unlock(philo->meal_lock);
	while (read_flag(&data->stop_flag, &data->stop_lock) == 0)
	{
		eat_routine_even(philo, data);
		if (read_flag(&data->stop_flag, &data->stop_lock) != 0)
			break ;
		sleep_routine(philo, data);
		if (read_flag(&data->stop_flag, &data->stop_lock) != 0)
			break ;
		think_routine(philo, data);
	}
	return (NULL);
}

void	*routine_odd(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	usleep(15000);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal_time = get_timestamp_millisec();
	pthread_mutex_unlock(philo->meal_lock);
	while (read_flag(&data->stop_flag, &data->stop_lock) == 0)
	{
		eat_routine_odd(philo, data);
		if (read_flag(&data->stop_flag, &data->stop_lock) != 0)
			break ;
		sleep_routine(philo, data);
		if (read_flag(&data->stop_flag, &data->stop_lock) != 0)
			break ;
		think_routine(philo, data);
	}
	return (NULL);
}
