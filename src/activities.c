/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:56:03 by omaly             #+#    #+#             */
/*   Updated: 2025/12/20 16:04:16 by omaly            ###   ########.fr       */
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

void	eat_routine_odd(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->right_fork);
	write_status(philo, data, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
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

void	eat_routine_even(t_philo *philo, t_data *data)
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
