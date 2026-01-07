/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:28:33 by omaly             #+#    #+#             */
/*   Updated: 2026/01/07 16:58:56 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data			data;
	pthread_t		*threads;
	pthread_mutex_t	*meal_locks;
	t_philo			*philos;
	t_fork			*forks;

	philos = NULL;
	threads = NULL;
	meal_locks = NULL;
	if (input_checker(argc, argv) != 0)
		return (1);
	if (data_setup(&data, argc, argv) != 0)
		return (2);
	if (forks_setup(&forks, data.philo_count) != 0)
		return (clean_data(&data), 3);
	if (meal_locks_setup(&meal_locks, data.philo_count) != 0)
		return (cleanup(philos, &data, forks, threads), 4);
	if (philos_setup(&philos, forks, meal_locks, &data) != 0)
		return (cleanup(philos, &data, forks, threads), 4);
	if (allocate_threads(&threads, data.philo_count) != 0)
		return (cleanup(philos, &data, forks, threads), 5);
	if (create_threads(threads, philos, &data) != 0)
		return (cleanup(philos, &data, forks, threads), 6);
	monitor(philos, meal_locks, &data);
	if (join_threads(threads, data.philo_count) != 0)
		return (cleanup(philos, &data, forks, threads), 7);
	cleanup(philos, &data, forks, threads);
	return (0);
}
