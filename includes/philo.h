/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:33:28 by omaly             #+#    #+#             */
/*   Updated: 2025/12/04 23:03:21 by omaly            ###   ########.fr       */
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
}					t_data;

typedef struct s_philo
{
	int				id;

	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	pthread_mutex_t	*stop_lock;
	pthread_mutex_t	*write_lock;
	int				*stop_flag;
	t_data			*data;

	int				meals_eaten;
	long			last_meal_time;
	pthread_mutex_t	meal_lock;
}					t_philo;

int					input_checker(int argc, char **argv);
void				write_status(t_philo *philo, char *s);
int					read_lock(int *ptr, pthread_mutex_t *mutex);
void				write_lock(int *ptr, pthread_mutex_t *mutex, int value);
void				*routine(void *arg);
int					allocate_threads(pthread_t **threads, size_t count);
int					data_setup(t_data *data, int argc, char **argv);
int					forks_setup(pthread_mutex_t **forks, size_t count);
int					philos_setup(t_philo **philos, pthread_mutex_t *forks,
						t_data *data);
long				get_time(void);
int					run_simulation(pthread_t *threads, t_philo *philos,
						size_t count);
#endif
