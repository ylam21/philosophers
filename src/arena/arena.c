/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:10:53 by omaly             #+#    #+#             */
/*   Updated: 2026/03/16 18:51:42 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/base.h"

void	arena_init(t_arena *arena, void *backing_buffer,
		t_u64 backing_buffer_len)
{
	arena->buffer = backing_buffer;
	arena->cap = backing_buffer_len;
	arena->pos = 0;
}

static t_u64	align_forward(t_u64 ptr, t_u64 align)
{
	return ((ptr + align - 1) & ~(align - 1));
}

void	*arena_push(t_arena *arena, t_u64 size)
{
	t_u64	current_ptr;
	t_u64	offset;
	void	*ptr;

	current_ptr = (t_u64)arena->buffer + arena->pos;
	offset = align_forward(current_ptr, sizeof(void *));
	offset -= (t_u64)arena->buffer;
	if (offset + size <= arena->cap)
	{
		ptr = (t_u8 *)arena->buffer + offset;
		arena->pos = offset + size;
		memset(ptr, 0, size);
		return (ptr);
	}
	return (0);
}

void	arena_pop_to(t_arena *arena, t_u64 pos)
{
	arena->pos = pos;
}
