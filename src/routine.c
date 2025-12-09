/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:03:14 by omaly             #+#    #+#             */
/*   Updated: 2025/12/09 23:22:00 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	sleep_routine(t_philo *philo, t_data *data)
{
	write_status(philo, data, "is sleeping");
	usleep(data->time_to_sleep * 1000);
}

void	think_routine(t_philo *philo, t_data *data)
{
	write_status(philo, data, "is thinking");
}

void	eat_routine(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->left_fork);
	write_status(philo, data, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	write_status(philo, data, "has taken a fork");
	write_status(philo, data, "is eating");
	pthread_mutex_lock(&data->meal_lock);
	philo->last_meal_time = get_timestamp_millisec();
	philo->meals_eaten = philo->meals_eaten + 1;
	pthread_mutex_unlock(&data->meal_lock);
	usleep(data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*handle_one_philo(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->left_fork);
	write_status(philo, data, "has taken a fork");
	usleep(data->time_to_die * 1000);
	pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (data->philo_count == 1)
		return (handle_one_philo(philo, data));
	if (philo->id % 2 == 0)
		usleep(1000);
	while (read_flag(&data->stop_flag, &data->stop_lock) == 0)
	{
		eat_routine(philo, data);
		if (read_flag(&data->stop_flag, &data->stop_lock) != 0)
			break ;
		sleep_routine(philo, data);
		if (read_flag(&data->stop_flag, &data->stop_lock) != 0)
			break ;
		think_routine(philo, data);
	}
	return (NULL);
}
