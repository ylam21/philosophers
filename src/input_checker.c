/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:33:11 by omaly             #+#    #+#             */
/*   Updated: 2025/12/03 18:56:52 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

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
		return (1);
	if (!argv)
		return (2);
	i = 1;
	while (i < argc)
	{
		if (has_digits_only(argv[i]) == false)
		{
			return (3);
		}
		i++;
	}
	return (0);
}
