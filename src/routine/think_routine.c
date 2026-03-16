/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:56:03 by omaly             #+#    #+#             */
/*   Updated: 2026/03/16 15:27:43 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/base.h"

void	think_routine(t_philo *philo, t_data *data)
{
	write_status(philo, data, "is thinking");
	if (data->philo_count % 2 == 1)
	{
		usleep(5000);
	}
}
