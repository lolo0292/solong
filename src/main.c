/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:21:58 by lleichtn          #+#    #+#             */
/*   Updated: 2025/02/10 16:29:27 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Gère la fermeture propre du jeu en cliquant sur la croix de la fenêtre
int	close_game(t_game *game)
{
	free_game(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2) // Vérifie si un fichier `.ber` est fourni
	{
		printf("Error\nUsage: ./so_long <map.ber>\n");
		return (1);
	}
	parse_map(argv[1], &game.map);   // Charge la carte
	check_map_validity(&game.map);   // Vérifie si la carte est correcte

	game.mlx = mlx_init();           // Initialise MiniLibX
	if (!game.mlx)
	{
		printf("Error\nImpossible d'initialiser MiniLibX\n");
		return (1);
	}
	game.win = mlx_new_window(game.mlx, game.map.width * 32,
			game.map.height * 32, "So Long"); // Crée une fenêtre
	if (!game.win)
	{
		printf("Error\nImpossible de créer la fenêtre\n");
		free(game.mlx);
		return (1);
	}
	game.moves = 0;                  // Initialise le compteur de déplacements

	load_textures(&game);            // Charge les textures
	render_map(&game);               // Affiche la carte

	// Ajoute les gestionnaires d'événements
	mlx_key_hook(game.win, handle_keypress, &game); // Déplacements clavier
	mlx_hook(game.win, 17, 0, close_game, &game);   // Fermeture avec la croix

	mlx_loop(game.mlx);              // Lancement de la boucle MiniLibX
	return (0);
}
