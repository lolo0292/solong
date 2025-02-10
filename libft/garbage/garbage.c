/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:36:22 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/30 12:56:18 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"

#include <stdio.h>
#include <stdlib.h>

// Initialiser le garbage collector
t_gc	*gc_init(void)
{
	t_gc *gc = malloc(sizeof(t_gc ));
	if (!gc)
	{
		fprintf(stderr, "Erreur : impossible d'allouer le garbage collector\n");
		return (NULL);
	}
	gc->head = NULL;
	return (gc);
}

// Ajouter un bloc au garbage collector
void	gc_add(t_gc *gc, void *ptr)
{
	t_garbage *node ;

	node = malloc(sizeof(t_garbage));
	if (!node)
	{
		fprintf(stderr, "Erreur : impossible d'ajouter un bloc au garbage collector\n");
		exit(EXIT_FAILURE);
	}
	node->ptr = ptr;
	node->next = gc->head;
	gc->head = node;
}

// Fonction pour allouer de la mémoire et l'ajouter au GC
void	*gc_malloc(t_gc *gc, size_t size)
{
	void *ptr ;

	ptr = malloc(size);
	if (!ptr) {
		fprintf(stderr, "Erreur : allocation mémoire échouée\n");
		return (NULL);
	}
	gc_add(gc, ptr);
	return (ptr);
}

// Libérer un bloc mémoire spécifique
void	gc_free_block(t_gc *gc, void *ptr)
{
	t_garbage	**indirect;
	t_garbage	*to_free;
	
	indirect = &gc->head;
	while (*indirect)
	{
		if ((*indirect)->ptr == ptr)
		{
			to_free = *indirect;
			*indirect = to_free->next;
			free(to_free->ptr);
			free(to_free);
			return;
		}
		indirect = &(*indirect)->next;
	}
}

// Libérer tous les blocs gérés par le garbage collector
void	gc_cleanup(t_gc *gc)
{
	t_garbage	*current;
	t_garbage	*to_free;

	current = gc->head;
	while (current)
	{
		to_free = current;
		current = current->next;
		free(to_free->ptr);
		free(to_free);
	}
	free(gc);
}
