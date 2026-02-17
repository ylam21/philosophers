/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_locks_setup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:56:52 by omaly             #+#    #+#             */
/*   Updated: 2026/02/17 10:18:51 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	meal_locks_setup(pthread_mutex_t **meal_locks, size_t philo_count)
{
	size_t	i;

	*meal_locks = malloc(philo_count * sizeof(pthread_mutex_t));
	if (*meal_locks == NULL)
		return (print_error(ERR_MALLOC));
	i = 0;
	while (i < philo_count)
	{
		if (pthread_mutex_init(&(*meal_locks)[i], NULL) != 0)
		{
			while (i > 0)
			{
				i--;
				pthread_mutex_destroy(&(*meal_locks)[i]);
			}
			free(*meal_locks);
			*meal_locks = NULL;
			return (print_error(ERR_MUTEX_INIT));
		}
		i++;
	}
	return (0);
}
