/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:03:14 by omaly             #+#    #+#             */
/*   Updated: 2025/12/20 16:04:43 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine_single(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	pthread_mutex_lock(philo->left_fork);
	write_status(philo, data, "has taken a fork");
	usleep(data->time_to_die * 1000);
	pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}

void	*routine_even(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	usleep(1000);
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
