/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:28:33 by omaly             #+#    #+#             */
/*   Updated: 2025/12/03 19:11:45 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine()
{
	printf("Hello there\n");
	return NULL;
}

typedef struct s_data
{
	int		philo_count;
	size_t	time_to_die;
	size_t	time_to_sleep;
	size_t	time_to_eat;
	int		total_meals;
}			t_data;

int	data_init(t_data *d, int argc, char **argv)
{
	if (!d)
		return (1);
	d->philo_count = atoi(argv[1]);
	d->time_to_die = atoi(argv[2]);
	d->time_to_eat = atoi(argv[3]);
	d->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		d->total_meals = atoi(argv[5]);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		d;
	pthread_t	*philos;
	int			i;

	if (input_checker(argc, argv) != 0)
	{
		return (print_error(ERR_INVALID_INPUT));
	}
	if (data_init(&d, argc, argv) != 0)
	{
		return (1);
	}
	philos = malloc(sizeof(philos) * (d.philo_count));
	if (!philos)
	{
		return (1);
	}
	i = 0;
	while (i < d.philo_count)
	{
		if (pthread_create(&philos[i], NULL, &routine, NULL) != 0)
		{
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < d.philo_count)
	{
		if (pthread_join(philos[i], NULL) != 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
