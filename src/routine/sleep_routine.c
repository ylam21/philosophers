/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:33:44 by omaly             #+#    #+#             */
/*   Updated: 2026/03/02 08:40:41 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sleep_routine(t_philo *philo, t_data *data)
{
	write_status(philo, data, "is sleeping");
	usleep(data->time_to_sleep * 1000);
}
