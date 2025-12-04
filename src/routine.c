/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:03:14 by omaly             #+#    #+#             */
/*   Updated: 2025/12/04 22:26:16 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	read_flag(int *flag, pthread_mutex_t *mutex)
{
	int	ret;

	pthread_mutex_lock(mutex);
	ret = *flag;
	pthread_mutex_unlock(mutex);
	return (ret);
}

void	write_status(t_philo *philo, char *s)
{
	int	current_time;
	int	timestamp;

	pthread_mutex_lock(philo->write_lock);
	if (read_flag(philo->stop_flag, philo->stop_lock) == 0)
	{
		current_time = get_time();
		timestamp = current_time - philo->data->start_time;
		printf("%zu %d %s\n", (long unsigned int)timestamp, philo->id, s);
	}
	pthread_mutex_unlock(philo->write_lock);
}

void	sleep_routine(t_philo *philo)
{
	write_status(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}

void	think_routine(t_philo *philo)
{
	int	time_to_think;

	time_to_think = 0;
	write_status(philo, "is thinking");
	usleep(time_to_think * 1000);
}

void	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	write_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	write_status(philo, "has taken a fork");
	write_status(philo, "is eating");
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = get_time();
	philo->meals_eaten = philo->meals_eaten + 1;
	pthread_mutex_unlock(&philo->meal_lock);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal_time = get_time();
	if (philo->id % 2 == 0)
		usleep(1000);
	while (read_flag(philo->stop_flag, philo->stop_lock) == 0)
	{
		eat_routine(philo);
		if (read_flag(philo->stop_flag, philo->stop_lock) != 0)
			break ;
		sleep_routine(philo);
		think_routine(philo);
	}
	return (NULL);
}
