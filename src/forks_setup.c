/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:40:04 by omaly             #+#    #+#             */
/*   Updated: 2025/12/05 15:35:45 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	forks_setup(pthread_mutex_t **forks, int fork_count)
{
	int	i;

	i = 0;
	if (fork_count == 0)
		return (print_error(ERR_ZERO_PHILO));
	*forks = malloc(sizeof(pthread_mutex_t) * fork_count);
	if (*forks == NULL)
		return (print_error(ERR_MALLOC));
	i = 0;
	while (i < fork_count)
	{
		if (pthread_mutex_init(&(*forks)[i], NULL) != 0)
		{
			while (--i)
			{
				if (pthread_mutex_destroy(&(*forks)[i]) != 0)
					print_error(ERR_MUTEX_DESTROY);
			}
			free(*forks);
			return (print_error(ERR_MUTEX_INIT));
		}
		i++;
	}
	return (0);
}
