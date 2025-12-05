/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:04:15 by omaly             #+#    #+#             */
/*   Updated: 2025/12/05 15:45:57 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philos_setup(t_philo **philos, pthread_mutex_t *forks, t_data *data)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * data->philo_count);
	if (*philos == NULL)
		return (print_error(ERR_MALLOC));
	i = 0;
	while (i < data->philo_count)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].data = data;
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].left_fork = &forks[i];
		(*philos)[i].right_fork = &forks[(i + 1) % data->philo_count];
		i++;
	}
	return (0);
}
