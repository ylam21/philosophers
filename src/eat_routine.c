/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:34:27 by omaly             #+#    #+#             */
/*   Updated: 2026/01/07 15:20:06 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#define TAKEN 1
#define RELEASED 0

void	change_fork_status(int *fork_status, int value)
{
	*fork_status = value;
	return ;
}

void	take_forks_odd(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->right_fork);
	change_fork_status(philo->right_fork_status, TAKEN);
	write_status(philo, data, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	change_fork_status(philo->left_fork_status, TAKEN);
	write_status(philo, data, "has taken a fork");
}

void	take_forks_even(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->left_fork);
	change_fork_status(philo->left_fork_status, TAKEN);
	write_status(philo, data, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	change_fork_status(philo->right_fork_status, TAKEN);
	write_status(philo, data, "has taken a fork");
}

void	eat_routine_odd(t_philo *philo, t_data *data)
{
	take_forks_odd(philo, data);
	write_status(philo, data, "is eating");
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal_time = get_timestamp_millisec();
	philo->meals_eaten = philo->meals_eaten + 1;
	pthread_mutex_unlock(philo->meal_lock);
	usleep(data->time_to_eat * 1000);
	change_fork_status(philo->left_fork_status, RELEASED);
	pthread_mutex_unlock(philo->left_fork);
	change_fork_status(philo->right_fork_status, RELEASED);
	pthread_mutex_unlock(philo->right_fork);
}

void	eat_routine_even(t_philo *philo, t_data *data)
{
	take_forks_even(philo, data);
	write_status(philo, data, "is eating");
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal_time = get_timestamp_millisec();
	philo->meals_eaten = philo->meals_eaten + 1;
	pthread_mutex_unlock(philo->meal_lock);
	usleep(data->time_to_eat * 1000);
	change_fork_status(philo->left_fork_status, RELEASED);
	pthread_mutex_unlock(philo->left_fork);
	change_fork_status(philo->right_fork_status, RELEASED);
	pthread_mutex_unlock(philo->right_fork);
}
