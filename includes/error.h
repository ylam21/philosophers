/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:00:09 by omaly             #+#    #+#             */
/*   Updated: 2025/12/04 21:50:13 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_INVALID_INPUT "Error: Invalid input\n"
# define ERR_CONFIG_SETUP "Error: Failed to setup t_config struct\n"
# define ERR_FORKS_SETUP "Error: Failed to setup forks\n"
# define ERR_PHILOS_SETUP "Error: Failed to setup philos\n"
# define ERR_STATE_SETUP "Error: Failed to setup state\n"
# define ERR_ALLOCATE_THREADS "Error: Failed to allocate threads\n"
# define ERR_RUN_SIMULATION "Error: Failed to run the simulation\n"

int	print_error(char *error_msg);
#endif
