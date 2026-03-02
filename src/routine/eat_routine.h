/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_routine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 08:34:58 by omaly             #+#    #+#             */
/*   Updated: 2026/03/02 08:40:29 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EAT_ROUTINE_H
#define EAT_ROUTINE_H

void	eat_routine_even(t_philo *philo, t_data *data);
void	eat_routine_odd(t_philo *philo, t_data *data);
void	take_forks_even(t_philo *philo, t_data *data);
void	take_forks_odd(t_philo *philo, t_data *data);
void	change_fork_status(int *fork_status, int value);

#endif