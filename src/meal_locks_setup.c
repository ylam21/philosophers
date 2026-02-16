/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_locks_setup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:56:52 by omaly             #+#    #+#             */
/*   Updated: 2026/01/21 15:25:45 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	meal_locks_setup(pthread_mutex_t **meal_locks, size_t philo_count)
{
	size_t	i;

	*meal_locks = malloc(philo_count * sizeof(pthread_mutex_t));
	if (*meal_locks == NULL)
	{
		return (print_error(ERR_MALLOC));
	}
	i = 0;
	while (i < philo_count)
	{
		if (pthread_mutex_init(&(*meal_locks)[i], NULL) != 0)
		{
			free(*meal_locks);
			return (print_error(ERR_MUTEX_INIT));
		}
		i++;
	}
	return (0);
}
