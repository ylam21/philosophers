/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:28:33 by omaly             #+#    #+#             */
/*   Updated: 2025/12/05 15:38:31 by omaly            ###   ########.fr       */
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
		return (1);
	if (data_setup(&data, argc, argv) != 0)
		return (2);
	if (forks_setup(&forks, data.philo_count) != 0)
		return (clean_data(&data), 3);
	if (philos_setup(&philos, forks, &data) != 0)
		return (cleanup(philos, &data, forks, threads), 4);
	if (allocate_threads(&threads, data.philo_count) != 0)
		return (cleanup(philos, &data, forks, threads), 5);
	if (run_simulation(threads, philos, &data) != 0)
		return (cleanup(philos, &data, forks, threads), 6);
	cleanup(philos, &data, forks, threads);
	return (0);
}
