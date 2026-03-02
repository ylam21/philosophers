/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 23:01:28 by omaly             #+#    #+#             */
/*   Updated: 2026/03/02 08:52:51 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	write_flag(int *ptr, pthread_mutex_t *mutex, int value)
{
	pthread_mutex_lock(mutex);
	*ptr = value;
	pthread_mutex_unlock(mutex);
}
