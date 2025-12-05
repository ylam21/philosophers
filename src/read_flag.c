/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:55:58 by omaly             #+#    #+#             */
/*   Updated: 2025/12/05 13:29:05 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	read_flag(int *ptr, pthread_mutex_t *mutex)
{
	int	read;

	pthread_mutex_lock(mutex);
	read = *ptr;
	pthread_mutex_unlock(mutex);
	return (read);
}
