/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:58:47 by omaly             #+#    #+#             */
/*   Updated: 2025/12/05 13:25:28 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	write_status(t_philo *philo, t_data *data, char *s)
{
	long	current_time;
	long	timestamp;

	pthread_mutex_lock(&data->write_lock);
	if (read_flag(&data->stop_flag, &data->stop_lock) == 0)
	{
		current_time = get_time();
		timestamp = current_time - data->start_time;
		printf("%ld %d %s\n", timestamp, philo->id, s);
	}
	pthread_mutex_unlock(&data->write_lock);
}
