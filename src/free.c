/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:18:29 by lleichtn          #+#    #+#             */
/*   Updated: 2025/02/10 16:18:54 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Libère le tableau `map->grid`
void	free_map(t_map *map)
{
	int y;

	y = 0;
	while (y < map->height)
	{
		free(map->grid[y]); // Libère chaque ligne de la carte
		y++;
	}
	free(map->grid); // Libère le tableau principal
}

// Libère toutes les textures chargées
void	free_textures(t_game *game)
{
	int i;

	i = 0;
	while (i < 5) // On a 5 textures (wall, floor, collectible, exit, player)
	{
		if (game->textures[i])
			mlx_destroy_image(game->mlx, game->textures[i]);
		i++;
	}
}

// Ferme la fenêtre et détruit MiniLibX proprement
void	free_game(t_game *game)
{
	free_textures(game);         // Supprime les images chargées
	free_map(&game->map);        // Libère la mémoire de la carte
	mlx_destroy_window(game->mlx, game->win); // Ferme la fenêtre MiniLibX
	mlx_destroy_display(game->mlx); // Détruit MiniLibX
	free(game->mlx);             // Libère MiniLibX
	printf("Mémoire libérée, fermeture du jeu.\n");
	exit(0);
}
