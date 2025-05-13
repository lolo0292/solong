/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:18:29 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/13 16:22:30 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Libère le tableau `map->grid`
void	free_map(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		free(map->grid[y]);
		y++;
	}
	free(map->grid);
}

// Libère toutes les textures chargées
void	free_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (game->textures[i])
			mlx_destroy_image(game->mlx, game->textures[i]);
		i++;
	}
}

// Ferme la fenêtre et détruit MiniLibX proprement
void	free_game(t_game *game)
{
	free_textures(game);
	free_map(&game->map);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	// printf("Mémoire libérée, fermeture du jeu.\n");
	exit(0);
}
