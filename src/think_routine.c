/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:56:03 by omaly             #+#    #+#             */
/*   Updated: 2026/01/07 19:00:47 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	think_routine_odd(t_philo *philo, t_data *data)
{
	write_status(philo, data, "is thinking");
	usleep(1000);
}

void	think_routine_even(t_philo *philo, t_data *data)
{
	write_status(philo, data, "is thinking");
}
