/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:33:28 by omaly             #+#    #+#             */
/*   Updated: 2025/12/09 23:20:15 by omaly            ###   ########.fr       */
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

typedef struct s_data
{
	int				philo_count;
	long			start_time;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				total_meals;

	int				stop_flag;
	pthread_mutex_t	stop_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
}					t_data;

typedef struct s_philo
{
	int				id;
	t_data			*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				meals_eaten;
	long			last_meal_time;
}					t_philo;

int					input_checker(int argc, char **argv);
void				write_status(t_philo *philo, t_data *data, char *s);
int					read_flag(int *ptr, pthread_mutex_t *mutex);
void				write_flag(int *ptr, pthread_mutex_t *mutex, int value);
void				*routine(void *arg);
int					allocate_threads(pthread_t **threads, int thread_count);
int					data_setup(t_data *data, int argc, char **argv);
int					forks_setup(pthread_mutex_t **forks, int fork_count);
int					philos_setup(t_philo **philos, pthread_mutex_t *forks,
						t_data *data);
long				get_timestamp_millisec(void);
void				cleanup(t_philo *philos, t_data *data,
						pthread_mutex_t *forks, pthread_t *threads);
void				clean_data(t_data *data);
void				clean_forks(pthread_mutex_t *forks, int fork_count);
int					create_threads(pthread_t *threads, t_philo *philos,
						t_data *data);
int					join_threads(pthread_t *threads, int thread_count);
void				monitor(t_philo *philos, t_data *data);

#endif
