/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:46:22 by omaly             #+#    #+#             */
/*   Updated: 2026/02/16 20:21:13 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	allocate_threads(pthread_t **threads, size_t philo_count)
{
	*threads = malloc(sizeof(pthread_t) * philo_count);
	if (*threads == NULL)
		return (print_error(ERR_MALLOC));
	return (0);
}

int	create_single_thread(pthread_t *threads, t_philo *philos, int idx)
{
	philos[idx].last_meal_time = get_timestamp_millisec();
	if (pthread_create(&threads[0], NULL, &routine_single, &philos[idx]) != 0)
		return (print_error(ERR_PTHREAD_CREATE));
	return (0);
}

int	create_threads(pthread_t *threads, t_philo *philos, t_data *data)
{
	size_t	i;

	i = 0;
	data->start_time = get_timestamp_millisec();
	if (data->philo_count == 1)
		return (create_single_thread(threads, philos, i));
	while (i < data->philo_count)
	{
		philos[i].last_meal_time = get_timestamp_millisec();
		if (i % 2 == 0)
		{
			if (pthread_create(&threads[i], NULL, &routine_even,
					&philos[i]) != 0)
				return (print_error(ERR_PTHREAD_CREATE));
		}
		else
		{
			if (pthread_create(&threads[i], NULL, &routine_odd,
					&philos[i]) != 0)
				return (print_error(ERR_PTHREAD_CREATE));
		}
		i++;
	}
	return (0);
}

int	join_threads(pthread_t *threads, size_t philo_count)
{
	size_t	i;

	i = 0;
	while (i < philo_count)
	{
		if (pthread_join(threads[i], NULL) != 0)
			return (print_error(ERR_PTHREAD_JOIN));
		i++;
	}
	return (0);
}
