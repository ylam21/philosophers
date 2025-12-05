/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 23:01:28 by omaly             #+#    #+#             */
/*   Updated: 2025/12/05 13:26:04 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	write_flag(int *ptr, pthread_mutex_t *mutex, int value)
{
	pthread_mutex_lock(mutex);
	*ptr = value;
	pthread_mutex_unlock(mutex);
}
