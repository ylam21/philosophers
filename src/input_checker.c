/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:33:11 by omaly             #+#    #+#             */
/*   Updated: 2025/12/05 15:36:57 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	has_digits_only(char *s)
{
	size_t	i;

	if (!s)
		return (false);
	if (s[0] == '\0')
		return (false);
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]) == 0)
		{
			print_error(ERR_NONDIGIT_ARG);
			return (false);
		}
		i++;
	}
	return (true);
}

int	input_checker(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (print_error(ERR_ARG_COUNT));
	i = 1;
	while (i < argc)
	{
		if (has_digits_only(argv[i]) == false)
			return (1);
		i++;
	}
	return (0);
}
