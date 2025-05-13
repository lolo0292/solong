/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:21:58 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/13 16:07:14 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Gère la fermeture propre du jeu en cliquant sur la croix de la fenêtre
int	close_game(t_game *game)
{
	free_game(game);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_game	game;

// 	if (argc != 2)
// 		return (1);
// 	parse_map(argv[1], &game.map);
// 	check_map_validity(&game.map);
// 	if (!is_valid_path(game.map.grid, game.map.player_x, game.map.player_y,
// 			game.map.width, game.map.height))
// 	{
// 		free_map(&game.map);
// 		return (1);
// 	}
// 	game.mlx = mlx_init();
// 	if (!game.mlx)
// 		return (1);
// 	game.win = mlx_new_window(game.mlx, game.map.width * 32,
// 			game.map.height * 32, "So Long");
// 	if (!game.win)
// 	{
// 		free(game.mlx);
// 		return (1);
// 	}
// 	game.moves = 0;
// 	load_textures(&game);
// 	render_map(&game);
// 	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
// 	mlx_hook(game.win, 17, 0, close_game, &game);
// 	mlx_loop(game.mlx);
// 	return (0);
// }

static int	init_and_run_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->win = mlx_new_window(game->mlx,
			game->map.width * 32,
			game->map.height * 32,
			"So Long");
	if (!game->win)
	{
		free(game->mlx);
		return (1);
	}
	game->moves = 0;
	load_textures(game);
	render_map(game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_dim	dim;

	if (argc != 2)
		return (1);
	parse_map(argv[1], &game.map);
	check_map_validity(&game.map);
	dim.w = game.map.width;
	dim.h = game.map.height;
	if (!is_valid_path(game.map.grid, game.map.player_x,
			game.map.player_y, dim))
	{
		free_map(&game.map);
		return (1);
	}
	return (init_and_run_game(&game));
}
