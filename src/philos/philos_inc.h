/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_inc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 09:02:34 by omaly             #+#    #+#             */
/*   Updated: 2026/03/02 09:06:52 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_INC_H
#define PHILOS_INC_H

void	clean_data(t_data *data);
void	clean_forks(t_fork *forks, size_t philo_count);
void	clean_meal_locks(pthread_mutex_t *meal_locks, size_t philo_count);
void	cleanup(t_state *state);
long	get_timestamp_millisec(void);
bool	has_digits_only(char *s);
int	input_checker(int argc, char **argv);
void	check_meals(t_philo *philos, pthread_mutex_t *meal_locks, t_data *data);
void	check_starvation(t_philo *philos, pthread_mutex_t *meal_locks,
		t_data *data);
void	monitor_default(t_philo *philos, pthread_mutex_t *meal_locks,
		t_data *data);
void	monitor_with_meals(t_philo *philos, pthread_mutex_t *meal_locks,
		t_data *data);
void	monitor(t_philo *philos, pthread_mutex_t *meal_locks, t_data *data);
int	read_flag(int *ptr, pthread_mutex_t *mutex);
int	allocate_threads(pthread_t **threads, size_t philo_count);
int	create_single_thread(pthread_t *threads, t_philo *philos, int idx);
int	create_threads(pthread_t *threads, t_philo *philos, t_data *data);
void	write_flag(int *ptr, pthread_mutex_t *mutex, int value);
void	write_status(t_philo *philo, t_data *data, char *status_msg);
void	write_death(t_philo *philo, t_data *data);

#endif