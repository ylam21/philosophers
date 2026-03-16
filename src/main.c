/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:28:33 by omaly             #+#    #+#             */
/*   Updated: 2026/03/16 18:28:25 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base.h"

int	main(int argc, char **argv)
{
	t_state		state;
	t_u8		backing_buffer[DEFAULT_ARENA_SIZE];

	if (input_checker(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (state_init(&state, backing_buffer, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (start_simulation(&state) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	monitor(&state);
	if (join_threads(state.threads, state.data.philo_count) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
