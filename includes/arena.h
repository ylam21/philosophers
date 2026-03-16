/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:10:49 by omaly             #+#    #+#             */
/*   Updated: 2026/03/16 18:49:59 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include "base.h"

typedef struct s_arena
{
	void	*buffer;
	t_u64	cap;
	t_u64	pos;
}			t_arena;

void		arena_init(t_arena *arena, void *backing_buffer,
				t_u64 backing_buffer_len);
void		*arena_push(t_arena *arena, t_u64 size);
void		arena_pop_to(t_arena *arena, t_u64 pos);

#endif
