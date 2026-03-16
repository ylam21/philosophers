/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:09:52 by omaly             #+#    #+#             */
/*   Updated: 2026/03/16 18:50:37 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/base.h"

static t_u8	is_out_of_bounds(t_s64 n, t_u8 sign)
{
	if (sign)
		n = n * -1;
	return (n > INT_MAX || n < INT_MIN);
}

static t_u8	is_negative(const char *s, t_u32 *i)
{
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
		{
			(*i)++;
			return (EXIT_FAILURE);
		}
		(*i)++;
	}
	return (EXIT_SUCCESS);
}

static t_u8	accumulate_number(const char *s, t_u32 i, t_s64 *ret, t_u8 sign)
{
	while (ft_isdigit(s[i]))
	{
		*ret = *ret * 10 + (s[i++] - '0');
		if (is_out_of_bounds(*ret, sign))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

t_u8	ft_atoi(const char *s, t_s32 *out)
{
	t_u32	i;
	t_u32	minus;
	t_s64	ret;

	if (!s || !out)
		return (EXIT_FAILURE);
	i = 0;
	while (is_whitespace(s[i]))
		i++;
	minus = is_negative(s, &i);
	ret = 0;
	if (ft_isdigit(s[i]) == 0)
		return (EXIT_FAILURE);
	if (accumulate_number(s, i, &ret, minus))
		return (EXIT_FAILURE);
	if (minus)
		ret = -ret;
	*out = (t_s32)ret;
	return (EXIT_SUCCESS);
}
