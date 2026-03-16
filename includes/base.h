/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:13:31 by omaly             #+#    #+#             */
/*   Updated: 2026/03/16 18:48:24 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include "types.h"
# include "arena.h"
# include "philo.h"
# include "init.h"
# include "routine.h"
# include "simulation.h"
# include "utils.h"

# define PROGRAM_NAME "philo"
# define DEFAULT_ARENA_SIZE 1048676
# define ERR_ATOI "Error: Atoi returned error\n"
# define ERR_ARG_COUNT "Error: Invalid argument count\n"
# define ERR_NONDIGIT_ARG "Error: One of the args has non-digit character\n"
# define ERR_MUTEX_INIT "Error: Failed to initialize mutex\n"
# define ERR_ZERO_PHILO "Error: No philos no fun\n"
# define ERR_ARENA_PUSH "Error: Failed to allocate memory onto arena\n"
# define ERR_PTHREAD_CREATE "Error: Failed to create threads\n"
# define ERR_PTHREAD_JOIN "Error: Failed to join threads\n"
# define ERR_GET_TIME "Error: Time does not exist bro\n"
# define FORK_TAKEN 1
# define FORK_RELEASED 0
# define SIM_FLAG_STOP 1
# define MONITOR_WMEALS_TRUE 1
# define MONITOR_WMEALS_FALSE 0

t_u8	input_checker(t_u32 argc, char **argv);

#endif
