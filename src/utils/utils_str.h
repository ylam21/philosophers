/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 08:28:38 by omaly             #+#    #+#             */
/*   Updated: 2026/03/02 09:09:43 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_STR_H
#define UTILS_STR_H

int	is_whitespace(char c);
int	ft_isdigit(char c);
int	is_out_of_bounds(long n, unsigned int sign);
int	is_negative(const char *s, unsigned int *i);
int	accumulate_number(const char *s, unsigned int i, long *ret, int sign);
int	ft_atoi(const char *s, int *out);

#endif