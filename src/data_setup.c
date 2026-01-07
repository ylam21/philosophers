/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:16:16 by omaly             #+#    #+#             */
/*   Updated: 2026/01/07 15:22:38 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	meal_locks_setup(pthread_mutex_t **meal_locks, int philo_count)
{
	int i;

	*meal_locks = malloc(philo_count * sizeof(pthread_mutex_t));
	if (meal_locks == NULL)
	{
		return (print_error(ERR_MALLOC));
	}
	i = 0;
	while (i < philo_count)
	{
		if (pthread_mutex_init(&(*meal_locks)[i], NULL) != 0)
			return (print_error(ERR_MUTEX_INIT));
		i++;
	}
	return 0;
}

int	data_setup(t_data *data, int argc, char **argv)
{
	if (ft_aatoi(argv[1], &data->philo_count) != 0)
		return (print_error(ERR_ATOI));
	if (ft_aatoi(argv[2], &data->time_to_die) != 0)
		return (print_error(ERR_ATOI));
	if (ft_aatoi(argv[3], &data->time_to_eat) != 0)
		return (print_error(ERR_ATOI));
	if (ft_aatoi(argv[4], &data->time_to_sleep) != 0)
		return (print_error(ERR_ATOI));
	if (argc == 6)
	{
		if (ft_aatoi(argv[5], &data->total_meals) != 0)
			return (print_error(ERR_ATOI));
	}
	else
		data->total_meals = -1;
	data->stop_flag = 0;
	if (pthread_mutex_init(&data->stop_lock, NULL) != 0)
		return (clean_data(data), print_error(ERR_MUTEX_INIT));
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		return (clean_data(data), print_error(ERR_MUTEX_INIT));
	if (meal_locks_setup(&data->meal_locks, data->philo_count) != 0)
		return (clean_data(data), 1);
	return (0);
}
