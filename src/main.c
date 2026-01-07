/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:28:33 by omaly             #+#    #+#             */
/*   Updated: 2026/01/07 13:43:07 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data			data;
	pthread_mutex_t	*forks;
	int				*forks_status;
	pthread_t		*threads;
	t_philo			*philos;

	threads = NULL;
	if (input_checker(argc, argv) != 0)
		return (1);
	if (data_setup(&data, argc, argv) != 0)
		return (2);
	if (forks_setup(&forks, &forks_status, data.philo_count) != 0)
		return (clean_data(&data), 3);
	if (philos_setup(&philos, forks, forks_status, &data) != 0)
		return (cleanup(philos, &data, forks, forks_status, threads), 4);
	if (allocate_threads(&threads, data.philo_count) != 0)
		return (cleanup(philos, &data, forks, forks_status, threads), 5);
	if (create_threads(threads, philos, &data) != 0)
		return (cleanup(philos, &data, forks, forks_status, threads), 6);
	monitor(philos, &data);
	if (join_threads(threads, data.philo_count) != 0)
		return (cleanup(philos, &data, forks, forks_status, threads), 7);
	cleanup(philos, &data, forks, forks_status, threads);
	return (0);
}
