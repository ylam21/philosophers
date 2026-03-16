/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:58:47 by omaly             #+#    #+#             */
/*   Updated: 2026/03/16 18:50:58 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/base.h"

void	write_status(t_philo *philo, t_data *data, char *status_msg)
{
	t_s32	timestamp;

	pthread_mutex_lock(&data->write_lock);
	if (read_u32ptr_safe(&data->stop_flag, &data->stop_lock) == 0)
	{
		timestamp = get_timestamp_millisec() - (t_s32)data->start_time;
		printf("%d %d %s\n", timestamp, philo->id, status_msg);
	}
	pthread_mutex_unlock(&data->write_lock);
}

void	write_death(t_philo *philo, t_data *data)
{
	t_s32	timestamp;

	pthread_mutex_lock(&data->write_lock);
	timestamp = get_timestamp_millisec() - (t_s32)data->start_time;
	printf("%d %d died\n", timestamp, philo->id);
	pthread_mutex_unlock(&data->write_lock);
}
