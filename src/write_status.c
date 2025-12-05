/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:58:47 by omaly             #+#    #+#             */
/*   Updated: 2025/12/05 15:46:49 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	write_status(t_philo *philo, t_data *data, char *s)
{
	int	timestamp;

	pthread_mutex_lock(&data->write_lock);
	if (read_flag(&data->stop_flag, &data->stop_lock) == 0)
	{
		timestamp = get_timestamp_millisec() - data->start_time;
		printf("%d %d %s\n", timestamp, philo->id, s);
	}
	pthread_mutex_unlock(&data->write_lock);
}
