/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:31:41 by omaly             #+#    #+#             */
/*   Updated: 2026/01/21 15:43:24 by omaly            ###   ########.fr       */
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

void	cleanup(t_state *state)
{
	clean_data(&state->data);
	if (state->forks)
		clean_forks(state->forks, state->data.philo_count);
	if (state->threads)
		free(state->threads);
	if (state->philos)
		free(state->philos);
	if (state->meal_locks)
		clean_meal_locks(state->meal_locks, state->data.philo_count);
}
