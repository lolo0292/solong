/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:35:34 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/30 12:54:55 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

# include "libft.h"

typedef struct s_garbage
{
	void *ptr;
	struct s_garbage *next;
} t_garbage;

typedef struct s_gc
{
	t_garbage *head;
} t_gc;

void	gc_free_block(t_gc *gc, void *ptr);
void	*gc_malloc(t_gc *gc, size_t size);
void	gc_add(t_gc *gc, void *ptr);
t_gc	*gc_init(void);
void	gc_cleanup(t_gc *gc);

#endif