/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:31:41 by omaly             #+#    #+#             */
/*   Updated: 2026/01/07 17:41:48 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clean_data(t_data *data)
{
	if (pthread_mutex_destroy(&data->stop_lock) != 0)
		print_error(ERR_MUTEX_DESTROY);
	if (pthread_mutex_destroy(&data->write_lock) != 0)
		print_error(ERR_MUTEX_DESTROY);
}

void	clean_forks(t_fork *forks, size_t philo_count)
{
	size_t	i;

	i = 0;
	while (i < philo_count)
	{
		if (pthread_mutex_destroy(&forks[i].fork_lock) != 0)
			print_error(ERR_MUTEX_DESTROY);
		i++;
	}
	free(forks);
}

void	clean_meal_locks(pthread_mutex_t *meal_locks, size_t philo_count)
{
	size_t	i;

	i = 0;
	while (i < philo_count)
	{
		if (pthread_mutex_destroy(&meal_locks[i]) != 0)
			print_error(ERR_MUTEX_DESTROY);
		i++;
	}
	free(meal_locks);
}

void	cleanup(t_philo *philos, t_data *data, t_fork *forks,
		pthread_t *threads, pthread_mutex_t *meal_locks)
{
	if (data)
		clean_data(data);
	if (forks)
		clean_forks(forks, data->philo_count);
	if (threads)
		free(threads);
	if (philos)
		free(philos);
	if (meal_locks)
		clean_meal_locks(meal_locks, data->philo_count);
}
