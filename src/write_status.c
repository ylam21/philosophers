/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:58:47 by omaly             #+#    #+#             */
/*   Updated: 2025/12/20 14:31:15 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	write_status(t_philo *philo, t_data *data, char *status_msg)
{
	long	timestamp;

	pthread_mutex_lock(&data->write_lock);
	if (read_flag(&data->stop_flag, &data->stop_lock) == 0)
	{
		timestamp = get_timestamp_millisec() - data->start_time;
		printf("%ld %d %s\n", timestamp, philo->id, status_msg);
	}
	pthread_mutex_unlock(&data->write_lock);
}

void	write_death(t_philo *philo, t_data *data)
{
	long	timestamp;

	pthread_mutex_lock(&data->write_lock);
	timestamp = get_timestamp_millisec() - data->start_time;
	printf("%ld %d died\n", timestamp, philo->id);
	pthread_mutex_unlock(&data->write_lock);
}