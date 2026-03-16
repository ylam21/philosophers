/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:25:15 by omaly             #+#    #+#             */
/*   Updated: 2026/03/16 18:27:07 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/base.h"

static t_u8	forks_init(t_state *state)
{
	t_u32	i;
	t_u32	size;

	size = state->data.philo_count;
	if (size == 0)
		return (print_error(ERR_ZERO_PHILO));
	state->forks = arena_push(&state->arena, size * sizeof(t_fork));
	if (state->forks == NULL)
		return (print_error(ERR_ARENA_PUSH));
	i = 0;
	while (i < size)
	{
		(state->forks)[i].fork_status = FORK_RELEASED;
		if (pthread_mutex_init(&(state->forks)[i].fork_lock, NULL) != 0)
		{
			return (print_error(ERR_MUTEX_INIT));
		}
		i += 1;
	}
	return (EXIT_SUCCESS);
}

static t_u8	meal_locks_init(t_state *state)
{
	t_u32	i;
	t_u32	size;

	size = state->data.philo_count;
	state->meal_locks = arena_push(&state->arena, size
			* sizeof(pthread_mutex_t));
	if (state->meal_locks == NULL)
		return (print_error(ERR_ARENA_PUSH));
	i = 0;
	while (i < size)
	{
		if (pthread_mutex_init(&(state->meal_locks)[i], NULL) != 0)
		{
			return (print_error(ERR_MUTEX_INIT));
		}
		i += 1;
	}
	return (EXIT_SUCCESS);
}

static t_u8	philos_init(t_state *state)
{
	t_u32	i;

	state->philos = arena_push(&state->arena, sizeof(t_philo)
			* state->data.philo_count);
	if (state->philos == NULL)
		return (print_error(ERR_ARENA_PUSH));
	i = 0;
	while (i < state->data.philo_count)
	{
		(state->philos)[i].id = i + 1;
		(state->philos)[i].data = &state->data;
		(state->philos)[i].meals_eaten = 0;
		(state->philos)[i].meal_lock = &state->meal_locks[i];
		(state->philos)[i].left_fork = &state->forks[i];
		(state->philos)[i].right_fork = &state->forks[(i + 1)
			% state->data.philo_count];
		i += 1;
	}
	return (EXIT_SUCCESS);
}

static t_u8	threads_init(t_state *state)
{
	state->threads = arena_push(&state->arena, state->data.philo_count
			* sizeof(pthread_t));
	if (state->threads == NULL)
		return (print_error(ERR_ARENA_PUSH));
	return (EXIT_SUCCESS);
}

t_u8	state_init(t_state *state, t_u8 *backing_buffer, int argc, char **argv)
{
	state->monitor_type = MONITOR_WMEALS_FALSE;
	arena_init(&state->arena, backing_buffer, DEFAULT_ARENA_SIZE);
	if (data_init(state, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (forks_init(state) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (meal_locks_init(state) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (philos_init(state) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (threads_init(state) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
