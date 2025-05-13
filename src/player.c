/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:08:46 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/13 16:16:30 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// // Vérifie si le déplacement est valide (pas un mur '1')
// int	can_move(t_game *game, int new_x, int new_y)
// {
// 	if (game->map.grid[new_y][new_x] == '1') // Si c'est un mur
// 		return (0);
// 	return (1);
// }

// // Met à jour la position du joueur et interagit avec la carte
// void	move_player(t_game *game, int dx, int dy)
// {
// 	int new_x = game->map.player_x + dx;
// 	int new_y = game->map.player_y + dy;

// 	if (!can_move(game, new_x, new_y)) // Vérifie si le joueur peut bouger
// 		return;

// 	if (game->map.grid[new_y][new_x] == 'C') // Si le joueur ramasse un objet
// 		game->map.collectibles--;

// 	if (game->map.grid[new_y]
// [new_x] == 'E' && game->map.collectibles == 0) // Victoire
// 	{
// 		write(1, "Well done champ", 15);
// 		exit(0);
// 	}

// 	game->map.grid[game->map.player_y]
// [game->map.player_x] = '0'; // Ancienne position devient du sol
// 	game->map.grid[new_y][new_x] = 'P'; // Nouvelle position du joueur
// 	game->map.player_x = new_x;
// 	game->map.player_y = new_y;
// 	game->moves++;

// 	render_map(game); // Rafraîchit l'affichage
// 	display_moves(game); // Affiche le compteur après chaque déplacement

// }

// // Gère les touches du clavier
// int	handle_keypress(int keycode, t_game *game)
// {
// 	if (keycode == 65307) // ESC pour quitter proprement
// 		free_game(game);
// 	else if (keycode == 119) // W (haut)
// 		move_player(game, 0, -1);
// 	else if (keycode == 97) // A (gauche)
// 		move_player(game, -1, 0);
// 	else if (keycode == 115) // S (bas)
// 		move_player(game, 0, 1);
// 	else if (keycode == 100) // D (droite)
// 		move_player(game, 1, 0);
// 	return (0);
// }

#include "so_long.h"

// Vérifie si le déplacement est valide (pas un mur '1')
int	can_move(t_game *game, int new_x, int new_y)
{
	if (game->map.grid[new_y][new_x] == '1')
		return (0);
	return (1);
}

// Met à jour la position du joueur et interagit avec la carte
void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->map.player_x + dx;
	new_y = game->map.player_y + dy;
	if (!can_move(game, new_x, new_y))
		return ;
	if (game->map.grid[new_y][new_x] == 'C')
	{
		game->map.collectibles--;
		game->map.grid[new_y][new_x] = '0';
	}
	if (game->map.grid[new_y][new_x] == 'E')
	{
		handle_exit(game, new_x, new_y);
		return ;
	}
	game->map.grid[game->map.player_y][game->map.player_x] = '0';
	game->map.grid[new_y][new_x] = 'P';
	game->map.player_x = new_x;
	game->map.player_y = new_y;
	game->moves++;
	render_map(game);
	display_moves(game);
}

// Gère les touches du clavier
int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		free_game(game);
	else if (keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 97)
		move_player(game, -1, 0);
	else if (keycode == 115)
		move_player(game, 0, 1);
	else if (keycode == 100)
		move_player(game, 1, 0);
	return (0);
}

// Empêche de finir tant qu'il reste des collectibles
void	handle_exit(t_game *game, int x, int y)
{
	(void)x;
	(void)y;
	if (game->map.collectibles == 0)
	{
		write(1, "Well done champ\n", 16);
		free_game(game);
	}
}
