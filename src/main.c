/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:28:33 by omaly             #+#    #+#             */
/*   Updated: 2026/03/02 09:10:41 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base/base_inc.h"
#include "philos/philos_inc.h"
#include "routine/routine_inc.h"
#include "utils/utils_inc.h"
#include "error/error_inc.h"
#include "setup/setup_inc.h"

#include "base/base_inc.c"
#include "philos/philos_inc.c"
#include "routine/routine_inc.c"
#include "utils/utils_inc.c"
#include "error/error_inc.c"
#include "setup/setup_inc.c"

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
