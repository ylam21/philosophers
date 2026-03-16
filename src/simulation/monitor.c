/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:47:42 by omaly             #+#    #+#             */
/*   Updated: 2026/03/16 18:51:53 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/base.h"

void	check_meals(t_philo *philos, pthread_mutex_t *meal_locks, t_data *data)
{
	t_u32	i;
	t_s32	limit;
	t_s32	meals_eaten;

	limit = data->total_meals;
	i = 0;
	while (i < data->philo_count)
	{
		meals_eaten = read_u32ptr_safe(&philos[i].meals_eaten, &meal_locks[i]);
		if (meals_eaten < limit)
			return ;
		i += 1;
	}
	write_u32ptr_safe(&data->stop_flag, &data->stop_lock, SIM_FLAG_STOP);
}

void	check_starvation(t_philo *philos, pthread_mutex_t *meal_locks,
		t_data *data)
{
	t_u32	i;
	t_u32	time_since_meal;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_lock(&meal_locks[i]);
		time_since_meal = (t_u32)get_timestamp_millisec()
			- philos[i].last_meal_time;
		pthread_mutex_unlock(&meal_locks[i]);
		if (time_since_meal > data->time_to_die)
		{
			write_u32ptr_safe(&data->stop_flag, &data->stop_lock,
				SIM_FLAG_STOP);
			write_death(&philos[i], data);
			break ;
		}
		i += 1;
	}
}

void	monitor_default(t_philo *philos, pthread_mutex_t *meal_locks,
		t_data *data)
{
	while (1)
	{
		check_starvation(philos, meal_locks, data);
		if (read_u32ptr_safe(&data->stop_flag,
				&data->stop_lock) == SIM_FLAG_STOP)
			break ;
		usleep(1000);
	}
}

void	monitor_with_meals(t_philo *philos, pthread_mutex_t *meal_locks,
		t_data *data)
{
	while (1)
	{
		check_starvation(philos, meal_locks, data);
		if (read_u32ptr_safe(&data->stop_flag,
				&data->stop_lock) == SIM_FLAG_STOP)
			break ;
		check_meals(philos, meal_locks, data);
		if (read_u32ptr_safe(&data->stop_flag,
				&data->stop_lock) == SIM_FLAG_STOP)
			break ;
		usleep(1000);
	}
}

void	monitor(t_state *state)
{
	if (state->monitor_type == MONITOR_WMEALS_TRUE)
		monitor_with_meals(state->philos, state->meal_locks, &state->data);
	else
		monitor_default(state->philos, state->meal_locks, &state->data);
	return ;
}
