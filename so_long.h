/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:01:10 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/13 16:06:41 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <signal.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>
// #include "mlx.h"
# include "libft/include/libft.h"
# include "libft/include/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include "libft/include/get_next_line.h"

typedef struct s_map {
    char **grid;      // Tableau 2D contenant la carte
    int width;        // Largeur de la carte
    int height;       // Hauteur de la carte
    int collectibles; // Nombre d’objets à ramasser (C)
    int player_x;     // Position X du joueur
    int player_y;     // Position Y du joueur
    int exit_x;       // Position X de la sortie
    int exit_y;       // Position Y de la sortie
} t_map;

typedef struct s_game
{
    void    *mlx;        // Pointeur sur MiniLibX
    void    *win;        // Pointeur sur la fenêtre MiniLibX
    t_map   map;         // Carte du jeu
    void    *textures[5];// Tableau des textures (mur, sol, collectible, sortie, joueur)
    int     tex_width;   // Largeur des textures
    int     tex_height;  // Hauteur des textures
    int     moves;       // Nombre de déplacements du joueur
}   t_game;

typedef struct s_dim
{
	int	w;
	int	h;
}	t_dim;


void	free_map(t_map *map);
void	free_textures(t_game *game);
void	free_game(t_game *game);
int	close_game(t_game *game);
void	is_map_enclosed(t_map *map);
void	count_elements(t_map *map, int *player, int *ex, int *collectibles);
void	has_required_elements(t_map *map);
void	check_map_validity(t_map *map);
void	map_dim(char *filename, t_map *map);
void	map_load(char *filename, t_map *map);
void	parse_map(char *filename, t_map *map);
int	can_move(t_game *game, int new_x, int new_y);
void	move_player(t_game *game, int dx, int dy);
int	handle_keypress(int keycode, t_game *game);
void	load_textures(t_game *game);
void	put_image(t_game *game, int x, int y, char tile);
void	render_map(t_game *game);
void	display_moves(t_game *game);
int	is_valid_path(char **map, int x, int y, t_dim dim);
void handle_exit(t_game *game, int x, int y);
void	check_map_characters(t_map *map);
int	check_map_name(char *filename);

#endif