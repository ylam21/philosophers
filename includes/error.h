/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:00:09 by omaly             #+#    #+#             */
/*   Updated: 2025/12/05 14:43:25 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_ATOI "Error: Atoi returned error\n"
# define ERR_ARG_COUNT "Error: Invalid argument count\n"
# define ERR_NONDIGIT_ARG "Error: One of the arguments has non-digit character\n"
# define ERR_MUTEX_INIT "Error: Failed to initialize mutex\n"
# define ERR_MUTEX_DESTROY "Error: Failed to destroy mutex\n"
# define ERR_ZERO_PHILO "Error: No philos no fun\n"
# define ERR_MALLOC "Error: Failed to malloc memory\n"
# define ERR_PTHREAD_CREATE "Error: Failed to create threads\n"
# define ERR_PTHREAD_JOIN "Error: Failed to join threads\n"
# define ERR_GET_TIME "Error: Time does not exist bro\n"

int	print_error(char *error_msg);
#endif
