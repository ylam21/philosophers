/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:33:28 by omaly             #+#    #+#             */
/*   Updated: 2026/01/07 17:37:19 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "error.h"
# include "utils.h"
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# define FORK_TAKEN 1
# define FORK_RELEASED 0

typedef struct s_data
{
	size_t			philo_count;
	long			start_time;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				total_meals;

	int				stop_flag;
	pthread_mutex_t	stop_lock;
	pthread_mutex_t	write_lock;
}					t_data;

typedef struct s_fork
{
	pthread_mutex_t	fork_lock;
	int				fork_status;
}					t_fork;

typedef struct s_philo
{
	t_data			*data;
	int				id;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_mutex_t	*meal_lock;
	int				meals_eaten;
	long			last_meal_time;
}					t_philo;

int					input_checker(int argc, char **argv);
int					meal_locks_setup(pthread_mutex_t **meal_locks,
						size_t philo_count);
void				write_status(t_philo *philo, t_data *data, char *s);
int					read_flag(int *ptr, pthread_mutex_t *mutex);
void				write_flag(int *ptr, pthread_mutex_t *mutex, int value);
int					allocate_threads(pthread_t **threads, size_t philo_count);
int					forks_setup(t_fork **forks, size_t philo_count);
int					data_setup(t_data *data, int argc, char **argv);
int					philos_setup(t_philo **philos, t_fork *forks,
						pthread_mutex_t *meal_locks, t_data *data);
void				clean_data(t_data *data);
void				cleanup(t_philo *philos, t_data *data, t_fork *forks,
						pthread_t *threads, pthread_mutex_t *meal_locks);
long				get_timestamp_millisec(void);
int					create_threads(pthread_t *threads, t_philo *philos,
						t_data *data);
int					join_threads(pthread_t *threads, size_t philo_count);
void				monitor(t_philo *philos, pthread_mutex_t *meal_locks,
						t_data *data);
void				*routine_single(void *arg);
void				*routine_even(void *arg);
void				*routine_odd(void *arg);
void				eat_routine_even(t_philo *philo, t_data *data);
void				eat_routine_odd(t_philo *philo, t_data *data);
void				think_routine(t_philo *philo, t_data *data);
void				sleep_routine(t_philo *philo, t_data *data);
void				change_fork_status(int *fork_status, int value);

#endif
