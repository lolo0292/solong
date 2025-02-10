/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:18:15 by lleichtn          #+#    #+#             */
/*   Updated: 2025/02/10 16:08:28 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Charge les textures dans MiniLibX
void	load_textures(t_game *game)
{
	game->textures[0] = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm",
			&game->tex_width, &game->tex_height);
	game->textures[1] = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm",
			&game->tex_width, &game->tex_height);
	game->textures[2] = mlx_xpm_file_to_image(game->mlx, "assets/collectible.xpm",
			&game->tex_width, &game->tex_height);
	game->textures[3] = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm",
			&game->tex_width, &game->tex_height);
	game->textures[4] = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm",
			&game->tex_width, &game->tex_height);
	if (!game->textures[0] || !game->textures[1] || !game->textures[2]
		|| !game->textures[3] || !game->textures[4])
	{
		printf("Error\nImpossible de charger les textures\n");
		exit(1);
	}
}

// Place la bonne image sur la carte selon le caractère de `map->grid`
void	put_image(t_game *game, int x, int y, char tile)
{
	void	*img;

	if (tile == '1')
		img = game->textures[0]; // Mur
	else if (tile == '0')
		img = game->textures[1]; // Sol
	else if (tile == 'C')
		img = game->textures[2]; // Collectible
	else if (tile == 'E')
		img = game->textures[3]; // Sortie
	else
		img = game->textures[4]; // Joueur
	mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y * 32);
}

// Affiche la carte complète dans la fenêtre MiniLibX
void	render_map(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			put_image(game, x, y, game->map.grid[y][x]);
			x++;
		}
		y++;
	}
}
// void	load_textures(t_game *game)
// {
// 	game->textures[0] = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm",
// 			&game->tex_width, &game->tex_height);
// 	game->textures[1] = mlx_xpm_file_to_image(game->mlx, "sprites/floor.xpm",
// 			&game->tex_width, &game->tex_height);
// 	game->textures[2] = mlx_xpm_file_to_image(game->mlx, "sprites/collectible.xpm",
// 			&game->tex_width, &game->tex_height);
// 	game->textures[3] = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm",
// 			&game->tex_width, &game->tex_height);
// 	game->textures[4] = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm",
// 			&game->tex_width, &game->tex_height);
// 	if (!game->textures[0] || !game->textures[1] || !game->textures[2]
// 		|| !game->textures[3] || !game->textures[4])
// 	{
// 		printf("Error\nImpossible de charger les textures\n");
// 		exit(1);
// 	}
// }
