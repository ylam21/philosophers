/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:28:33 by omaly             #+#    #+#             */
/*   Updated: 2026/01/21 15:44:06 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init(pthread_t **threads, pthread_mutex_t **meal_locks,
		t_philo **philos, t_fork **forks)
{
	*threads = NULL;
	*meal_locks = NULL;
	*philos = NULL;
	*forks = NULL;
	return ;
}

int	main(int argc, char **argv)
{
	t_state	state;

	init(&state.threads, &state.meal_locks, &state.philos, &state.forks);
	if (input_checker(argc, argv) != 0)
		return (1);
	if (data_setup(&state.data, argc, argv) != 0)
		return (2);
	if (forks_setup(&state.forks, state.data.philo_count) != 0)
		return (clean_data(&state.data), 3);
	if (meal_locks_setup(&state.meal_locks, state.data.philo_count) != 0)
		return (cleanup(&state), 4);
	if (philos_setup(&state.philos, state.forks, state.meal_locks,
			&state.data) != 0)
		return (cleanup(&state), 5);
	if (allocate_threads(&state.threads, state.data.philo_count) != 0)
		return (cleanup(&state), 6);
	if (create_threads(state.threads, state.philos, &state.data) != 0)
		return (cleanup(&state), 7);
	monitor(state.philos, state.meal_locks, &state.data);
	if (join_threads(state.threads, state.data.philo_count) != 0)
		return (cleanup(&state), 8);
	cleanup(&state);
	return (0);
}
