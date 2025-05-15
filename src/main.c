/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:21:58 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/15 17:07:49 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// Gère la fermeture propre du jeu en cliquant sur la croix de la fenêtre
// int	close_game(t_game *game)
// {
// 	free_game(game);
// 	return (0);
// }

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
// 		return (1);printf
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

// static int	init_and_run_game(t_game *game)
// {
// 	game->mlx = mlx_init();
// 	if (!game->mlx)
// 		return (1);
// 	game->win = mlx_new_window(game->mlx,
// 			game->map.width * 32,
// 			game->map.height * 32,
// 			"So Long");
// 	if (!game->win)
// 	{
// 		free(game->mlx);
// 		return (1);
// 	}
// 	game->moves = 0;
// 	load_textures(game);
// 	render_map(game);
// 	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
// 	mlx_hook(game->win, 17, 0, close_game, game);
// 	mlx_loop(game->mlx);
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	t_game	game;
// 	t_dim	dim;

// 	if (argc != 2)
// 		return (1);
// 	parse_map(argv[1], &game.map);
// 	check_map_validity(&game.map);
// 	dim.w = game.map.width;
// 	dim.h = game.map.height;
// 	if (!is_valid_path(game.map.grid, game.map.player_x,
// 			game.map.player_y, dim))
// 	{
// 		free_map(&game.map);
// 		return (1);
// 	}
// 	return (init_and_run_game(&game));
// }

// static int	init_and_run_game(t_game *game)
// {
// 	game->mlx = mlx_init();
// 	if (!game->mlx)
// 		return (1);
// 	game->win = mlx_new_window(game->mlx,
// 			game->map.width * 32,
// 			game->map.height * 32,
// 			"So Long");
// 	if (!game->win)
// 	{
// 		free(game->mlx);
// 		return (1);
// 	}
// 	game->moves = 0;
// 	load_textures(game);
// 	render_map(game);
// 	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
// 	mlx_hook(game->win, 17, 0, close_game, game);
// 	mlx_loop(game->mlx);
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	t_game	game;
// 	t_dim	dim;

// 	if (argc != 2)
// 		return (1);
// 	parse_map(argv[1], &game.map);
// 	check_map_validity(&game.map);
// 	dim.w = game.map.width;
// 	dim.h = game.map.height;
// 	if (!is_valid_path(game.map.grid, game.map.player_x,
// 			game.map.player_y, dim))
// 	{
// 		free_map(&game.map);
// 		return (1);
// 	}
// 	return (init_and_run_game(&game));
// }

// static int	init_and_run_game(t_game *game)
// {
// 	int	screen_w;
// 	int	screen_h;

// 	game->mlx = mlx_init();
// 	if (!game->mlx)
// 		return (1);
// 	mlx_get_screen_size(game->mlx, &screen_w, &screen_h);
// 	if (game->map.width * 32 > screen_w
// 		|| game->map.height * 32 > screen_h)
// 	{
// 		write(2, "Error\nMap too big for screen\n", 30);
// 		free(game->mlx);
// 		return (1);
// 	}
// 	game->win = mlx_new_window(game->mlx,
// 			game->map.width * 32,
// 			game->map.height * 32,
// 			"So Long");
// 	if (!game->win)
// 	{
// 		free(game->mlx);
// 		return (1);
// 	}
// 	game->moves = 0;
// 	load_textures(game);
// 	render_map(game);
// 	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
// 	mlx_hook(game->win, 17, 0, close_game, game);
// 	mlx_loop(game->mlx);
// 	return (0);
// }

// 		|| game->map.height * 32 > screen_h)
// 	{
// 		write(2, "Error\nMap too big for screen\n", 30);
// 		free(game->mlx);
// 		return (1);
// 	}
// 	game->win = mlx_new_window(game->mlx,
// 			game->map.width * 32,
// 			game->map.height * 32,
// 			"So Long");
// 	if (!game->win)
// 	{
// 		free(game->mlx);
// 		return (1);
// 	}
// 	game->moves = 0;
// 	load_textures(game);
// 	render_map(game);
// 	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
// 	mlx_hook(game->win, 17, 0, close_game, game);
// 	mlx_loop(game->mlx);
// 	return (0);
// }
#include "so_long.h"

int	close_game(t_game *game)
{
	free_game(game);
	return (0);
}

// static int	create_window_and_check_size(t_game *game)
// {
// 	int	screen_w;
// 	int	screen_h;

// 	mlx_get_screen_size(game->mlx, &screen_w, &screen_h);
// 	if (game->map.width * 32 > screen_w
// 		|| game->map.height * 32 > screen_h)
// 	{
// 		write(2, "Error\nMap too big for screen\n", 30);
// 		free(game->mlx);
// 		return (1);
// 	}
// 	game->win = mlx_new_window(game->mlx,
// 			game->map.width * 32,
// 			game->map.height * 32,
// 			"So Long");
// 	if (!game->win)
// 	{
// 		free(game->mlx);
// 		return (1);
// 	}
// 	return (0);
// }
static int	create_window_and_check_size(t_game *game)
{
	int	screen_w;
	int	screen_h;

	mlx_get_screen_size(game->mlx, &screen_w, &screen_h);
	if (game->map.width * 32 > screen_w
		|| game->map.height * 32 > screen_h)
	{
		write(2, "Error\nMap too big for screen\n", 30);
		free_map(&game->map);           // 💥 libère la map
		get_next_line(-1);              // 💥 libère stash
		mlx_destroy_display(game->mlx); // 💥 libère display
		free(game->mlx);                // 💥 libère mlx
		return (1);
	}
	game->win = mlx_new_window(game->mlx,
			game->map.width * 32,
			game->map.height * 32,
			"So Long");
	if (!game->win)
	{
		free_map(&game->map);
		get_next_line(-1);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (1);
	}
	return (0);
}

static int	init_and_run_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	if (create_window_and_check_size(game))
		return (1);
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
		get_next_line(-1);
		return (1);
	}
	init_and_run_game(&game);
	free_map(&game.map);
	get_next_line(-1);
	return (0);
}
