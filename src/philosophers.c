/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:28:33 by omaly             #+#    #+#             */
/*   Updated: 2025/12/05 12:10:00 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data			data;
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	t_philo			*philos;

	if (input_checker(argc, argv) != 0)
		return (print_error(ERR_INVALID_INPUT));
	if (data_setup(&data, argc, argv) != 0)
		return (print_error(ERR_CONFIG_SETUP));
	if (forks_setup(&forks, data.philo_count) != 0)
		return (print_error(ERR_FORKS_SETUP));
	if (philos_setup(&philos, forks, &data) != 0)
		return (print_error(ERR_PHILOS_SETUP));
	if (allocate_threads(&threads, data.philo_count) != 0)
		return (print_error(ERR_ALLOCATE_THREADS));
	if (run_simulation(threads, philos, &data, data.philo_count) != 0)
		return (print_error(ERR_RUN_SIMULATION));
	return (0);
}
