/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:24:35 by omaly             #+#    #+#             */
/*   Updated: 2026/03/16 18:52:15 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/base.h"

t_u8	create_single_thread(pthread_t *threads, t_philo *philos, t_u32 idx)
{
	philos[idx].last_meal_time = get_timestamp_millisec();
	if (pthread_create(&threads[0], NULL, &routine_single, &philos[idx]) != 0)
		return (print_error(ERR_PTHREAD_CREATE));
	return (EXIT_SUCCESS);
}

t_u8	join_threads(pthread_t *threads, t_u32 philo_count)
{
	t_u64	i;

	i = 0;
	while (i < philo_count)
	{
		if (pthread_join(threads[i], NULL) != 0)
			return (print_error(ERR_PTHREAD_JOIN));
		i++;
	}
	return (EXIT_SUCCESS);
}

t_u8	start_simulation(t_state *state)
{
	t_u32	i;

	i = 0;
	state->data.start_time = (t_u32)get_timestamp_millisec();
	if (state->data.philo_count == 1)
		return (create_single_thread(state->threads, state->philos, i));
	while (i < (t_u32)state->data.philo_count)
	{
		(state->philos)[i].last_meal_time = (t_u32)get_timestamp_millisec();
		if (i & 1)
		{
			if (pthread_create(&(state->threads)[i], NULL, &routine_odd,
				&(state->philos)[i]) != 0)
				return (print_error(ERR_PTHREAD_CREATE));
		}
		else
		{
			if (pthread_create(&(state->threads)[i], NULL, &routine_even,
				&(state->philos)[i]) != 0)
				return (print_error(ERR_PTHREAD_CREATE));
		}
		i += 1;
	}
	return (EXIT_SUCCESS);
}
