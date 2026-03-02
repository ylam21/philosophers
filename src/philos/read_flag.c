/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:55:58 by omaly             #+#    #+#             */
/*   Updated: 2026/03/02 08:52:40 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	read_flag(int *ptr, pthread_mutex_t *mutex)
{
	int	read;

	pthread_mutex_lock(mutex);
	read = *ptr;
	pthread_mutex_unlock(mutex);
	return (read);
}
