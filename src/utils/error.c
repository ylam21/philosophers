/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:55:21 by omaly             #+#    #+#             */
/*   Updated: 2026/03/16 18:50:52 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/base.h"

static void	ft_putstr_fd(char *s, t_s32 fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

t_u8	print_error(char *error_msg)
{
	ft_putstr_fd(error_msg, STDERR_FILENO);
	return (EXIT_FAILURE);
}
