/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:56:44 by omaly             #+#    #+#             */
/*   Updated: 2026/03/16 18:50:14 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include "base.h"

void	*routine_odd(void *arg);
void	*routine_even(void *arg);
void	*routine_single(void *arg);
void	eat_routine_even(t_philo *philo, t_data *data);
void	eat_routine_odd(t_philo *philo, t_data *data);
void	sleep_routine(t_philo *philo, t_data *data);
void	think_routine(t_philo *philo, t_data *data);
void	change_fork_status(int *fork_status, int value);

#endif
