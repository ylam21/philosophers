/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 18:45:19 by omaly             #+#    #+#             */
/*   Updated: 2026/03/16 18:50:25 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "base.h"

typedef struct s_data
{
	t_u32			philo_count;
	t_s32			start_time;
	t_u32			time_to_die;
	t_u32			time_to_sleep;
	t_u32			time_to_eat;
	t_u32			total_meals;

	t_u32			stop_flag;
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
	t_u32			id;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_mutex_t	*meal_lock;
	t_u32			meals_eaten;
	t_s32			last_meal_time;
}					t_philo;

typedef struct s_state
{
	t_arena			arena;
	t_data			data;
	pthread_t		*threads;
	pthread_mutex_t	*meal_locks;
	t_philo			*philos;
	t_fork			*forks;
	t_u8			monitor_type;
}					t_state;
#endif
