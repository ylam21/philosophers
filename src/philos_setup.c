/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:04:15 by omaly             #+#    #+#             */
/*   Updated: 2025/12/04 22:20:10 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philos_setup(t_philo **philos, pthread_mutex_t *forks, t_data *data)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * data->philo_count);
	if (*philos == NULL)
		return (1);
	i = 0;
	while (i < data->philo_count)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].data = data;
		(*philos)[i].stop_lock = &data->stop_lock;
		(*philos)[i].write_lock = &data->write_lock;
		(*philos)[i].stop_flag = &data->stop_flag;
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].last_meal_time = 0;
		pthread_mutex_init(&(*philos)[i].meal_lock, NULL);
		(*philos)[i].left_fork = &forks[i];
		(*philos)[i].right_fork = &forks[(i + 1) % data->philo_count];
		i++;
	}
	return (0);
}
