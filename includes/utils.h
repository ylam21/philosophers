/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:10:32 by omaly             #+#    #+#             */
/*   Updated: 2026/03/16 18:17:29 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

t_u8	ft_atoi(const char *s, t_s32 *out);
t_u8	ft_isdigit(char c);
t_u8	is_whitespace(char c);
t_u8	print_error(char *error_msg);
t_s32	get_timestamp_millisec(void);
t_u32	read_u32ptr_safe(t_u32 *ptr, pthread_mutex_t *mutex);
void	write_u32ptr_safe(t_u32 *ptr, pthread_mutex_t *mutex, t_s32 value);
void	write_status(t_philo *philo, t_data *data, char *status_msg);
void	write_death(t_philo *philo, t_data *data);

#endif
