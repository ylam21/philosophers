/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u32_rw_safe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:52:55 by omaly             #+#    #+#             */
/*   Updated: 2026/03/16 17:02:15 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/base.h"

t_u32	read_u32ptr_safe(t_u32 *ptr, pthread_mutex_t *mutex)
{
	t_u32	read;

	pthread_mutex_lock(mutex);
	read = *ptr;
	pthread_mutex_unlock(mutex);
	return (read);
}

void	write_u32ptr_safe(t_u32 *ptr, pthread_mutex_t *mutex, t_s32 value)
{
	pthread_mutex_lock(mutex);
	*ptr = value;
	pthread_mutex_unlock(mutex);
}
