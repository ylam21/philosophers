/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:46:22 by omaly             #+#    #+#             */
/*   Updated: 2025/12/04 16:02:27 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	allocate_threads(pthread_t **threads, size_t count)
{
	if (threads == NULL)
		return (1);
	*threads = malloc(sizeof(pthread_t) * count);
	if (*threads == NULL)
		return (2);
	return (0);
}
