/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_inc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 08:58:29 by omaly             #+#    #+#             */
/*   Updated: 2026/03/02 08:59:58 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_INC_H
#define SETUP_INC_H

int	data_setup(t_data *data, int argc, char **argv);
int	forks_setup(t_fork **forks, size_t philo_count);
int	meal_locks_setup(pthread_mutex_t **meal_locks, size_t philo_count);
int	philos_setup(t_philo **philos, t_fork *forks, pthread_mutex_t *meal_locks,
		t_data *data);

#endif