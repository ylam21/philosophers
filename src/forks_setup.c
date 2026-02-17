/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:40:04 by omaly             #+#    #+#             */
/*   Updated: 2026/02/17 10:11:13 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	forks_setup(t_fork **forks, size_t philo_count)
{
	size_t	i;

	if (philo_count == 0)
		return (print_error(ERR_ZERO_PHILO));
	*forks = malloc(philo_count * sizeof(t_fork));
	if (*forks == NULL)
		return (print_error(ERR_MALLOC));
	i = 0;
	while (i > 0)
	{
		i--;
		(*forks)[i].fork_status = FORK_RELEASED;
		if (pthread_mutex_init(&(*forks)[i].fork_lock, NULL) != 0)
		{
			while (--i)
			{
				if (pthread_mutex_destroy(&(*forks)[i].fork_lock) != 0)
					print_error(ERR_MUTEX_DESTROY);
			}
			free(*forks);
			return (print_error(ERR_MUTEX_INIT));
		}
		i++;
	}
	return (0);
}
