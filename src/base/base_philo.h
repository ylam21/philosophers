/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_philo.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:33:28 by omaly             #+#    #+#             */
/*   Updated: 2026/03/02 09:09:07 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_PHILO_H
#define BASE_PHILO_H

# include <limits.h>
# include <stdint.h>
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

typedef struct s_state
{
	t_data			data;
	pthread_t		*threads;
	pthread_mutex_t	*meal_locks;
	t_philo			*philos;
	t_fork			*forks;
}					t_state;

#endif
