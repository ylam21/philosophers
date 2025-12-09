/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:46:22 by omaly             #+#    #+#             */
/*   Updated: 2025/12/09 23:17:25 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	allocate_threads(pthread_t **threads, int thread_count)
{
	*threads = malloc(sizeof(pthread_t) * thread_count);
	if (*threads == NULL)
		return (print_error(ERR_MALLOC));
	return (0);
}

int	create_threads(pthread_t *threads, t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_timestamp_millisec();
	while (i < data->philo_count)
	{
		philos[i].last_meal_time = get_timestamp_millisec();
		if (pthread_create(&threads[i], NULL, &routine, &philos[i]) != 0)
			return (print_error(ERR_PTHREAD_CREATE));
		i++;
	}
	return (0);
}

int	join_threads(pthread_t *threads, int thread_count)
{
	int	i;

	i = 0;
	while (i < thread_count)
	{
		if (pthread_join(threads[i], NULL) != 0)
			return (print_error(ERR_PTHREAD_JOIN));
		i++;
	}
	return (0);
}
