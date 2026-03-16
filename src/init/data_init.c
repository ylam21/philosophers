/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:21:04 by omaly             #+#    #+#             */
/*   Updated: 2026/03/16 16:59:54 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/base.h"

t_u8	data_init(t_state *state, int argc, char **argv)
{
	if (ft_atoi(argv[1], (t_s32 *)&state->data.philo_count) == EXIT_FAILURE)
		return (print_error(ERR_ATOI));
	if (state->data.philo_count == 0)
		return (print_error(ERR_ZERO_PHILO));
	if (ft_atoi(argv[2], (t_s32 *)&state->data.time_to_die) == EXIT_FAILURE)
		return (print_error(ERR_ATOI));
	if (ft_atoi(argv[3], (t_s32 *)&state->data.time_to_eat) == EXIT_FAILURE)
		return (print_error(ERR_ATOI));
	if (ft_atoi(argv[4], (t_s32 *)&state->data.time_to_sleep) == EXIT_FAILURE)
		return (print_error(ERR_ATOI));
	if (argc == 6)
	{
		state->monitor_type = MONITOR_WMEALS_TRUE;
		if (ft_atoi(argv[5], (t_s32 *)&state->data.total_meals) != 0)
			return (print_error(ERR_ATOI));
	}
	state->data.stop_flag = 0;
	if (pthread_mutex_init(&state->data.stop_lock, NULL) != 0)
		return (print_error(ERR_MUTEX_INIT));
	if (pthread_mutex_init(&state->data.write_lock, NULL) != 0)
		return (print_error(ERR_MUTEX_INIT));
	return (EXIT_SUCCESS);
}
