/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:31:41 by omaly             #+#    #+#             */
/*   Updated: 2025/12/05 12:38:35 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	cleanup(t_philo *philos, t_data *data, pthread_mutex_t *forks,
		pthread_t *threads)
{
	int	i;

	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->stop_lock);
	pthread_mutex_destroy(&data->write_lock);
	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
	free(threads);
	free(philos);
}
