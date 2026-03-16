/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:20:38 by omaly             #+#    #+#             */
/*   Updated: 2026/03/16 18:50:07 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "base.h"

t_u8	data_init(t_state *state, int argc, char **argv);
t_u8	state_init(t_state *state, t_u8 *backing_buffer, int argc, char **argv);

#endif
