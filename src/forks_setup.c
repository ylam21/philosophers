/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:40:04 by omaly             #+#    #+#             */
/*   Updated: 2025/12/05 12:13:58 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	forks_init(pthread_mutex_t *forks, size_t count)
{
	size_t	i;

	if (forks == NULL)
		return (1);
	i = 0;
	while (i < count)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			while (i > 0)
			{
				i--;
				pthread_mutex_destroy(&forks[i]);
			}
			return (2);
		}
		i++;
	}
	return (0);
}

int	forks_setup(pthread_mutex_t **forks, size_t count)
{
	*forks = malloc(sizeof(pthread_mutex_t) * count);
	if (*forks == NULL)
		return (1);
	if (forks_init(*forks, count) != 0)
	{
		free(*forks);
		return (2);
	}
	return (0);
}
