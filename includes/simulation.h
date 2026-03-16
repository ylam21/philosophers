/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:58:26 by omaly             #+#    #+#             */
/*   Updated: 2026/03/16 18:50:19 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "base.h"

void	monitor(t_state *state);
void	monitor_with_meals(t_philo *philos, pthread_mutex_t *meal_locks,
			t_data *data);
void	monitor_default(t_philo *philos, pthread_mutex_t *meal_locks,
			t_data *data);
void	check_starvation(t_philo *philos, pthread_mutex_t *meal_locks,
			t_data *data);
void	check_meals(t_philo *philos, pthread_mutex_t *meal_locks, t_data *data);
t_u8	create_single_thread(pthread_t *threads, t_philo *philos, t_u32 idx);
t_u8	join_threads(pthread_t *threads, t_u32 philo_count);
t_u8	start_simulation(t_state *state);

#endif
