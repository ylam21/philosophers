/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp_millisec.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:57:03 by omaly             #+#    #+#             */
/*   Updated: 2026/03/16 17:02:27 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/base.h"

t_s32	get_timestamp_millisec(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		print_error(ERR_GET_TIME);
		return (-1);
	}
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}
