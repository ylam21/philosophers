/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 08:28:35 by omaly             #+#    #+#             */
/*   Updated: 2026/03/02 08:28:36 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_whitespace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}

int	ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

int	is_out_of_bounds(long n, unsigned int sign)
{
	if (sign)
		n = n * -1;
	return (n > INT_MAX || n < INT_MIN);
}

int	is_negative(const char *s, unsigned int *i)
{
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
		{
			(*i)++;
			return (1);
		}
		(*i)++;
	}
	return (0);
}

int	accumulate_number(const char *s, unsigned int i, long *ret, int sign)
{
	while (ft_isdigit(s[i]))
	{
		*ret = *ret * 10 + (s[i++] - '0');
		if (is_out_of_bounds(*ret, sign))
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *s, int *out)
{
	unsigned int	i;
	unsigned int	minus;
	long			ret;

	if (!s || !out)
		return (1);
	i = 0;
	while (is_whitespace(s[i]))
		i++;
	minus = is_negative(s, &i);
	ret = 0;
	if (ft_isdigit(s[i]) == 0)
		return (2);
	if (accumulate_number(s, i, &ret, minus))
		return (3);
	if (minus)
		ret = -ret;
	*out = (int)ret;
	return (0);
}
