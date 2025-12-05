/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:16:16 by omaly             #+#    #+#             */
/*   Updated: 2025/12/05 16:17:07 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
	if (pthread_mutex_init(&data->meal_lock, NULL) != 0)
		return (clean_data(data), print_error(ERR_MUTEX_INIT));
	return (0);
}
