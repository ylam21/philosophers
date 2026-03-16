/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:33:11 by omaly             #+#    #+#             */
/*   Updated: 2026/03/16 17:01:39 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base.h"

static t_u8	has_digits_only(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	if (s[0] == '\0')
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]) == 0)
		{
			print_error(ERR_NONDIGIT_ARG);
			return (0);
		}
		i++;
	}
	return (1);
}

t_u8	input_checker(t_u32 argc, char **argv)
{
	t_u64	i;

	if (argc != 5 && argc != 6)
	{
		return (print_error(ERR_ARG_COUNT));
	}
	i = 1;
	while (i < argc)
	{
		if (has_digits_only(argv[i]) == 0)
		{
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
