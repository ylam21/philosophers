/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:46:22 by omaly             #+#    #+#             */
/*   Updated: 2025/12/05 15:20:54 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	allocate_threads(pthread_t **threads, int thread_count)
{
	*threads = malloc(sizeof(pthread_t) * thread_count);
	if (*threads == NULL)
		return (print_error(ERR_MALLOC));
	return (0);
}
