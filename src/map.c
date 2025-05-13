/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:04:03 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/13 16:15:28 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// // Opem .ber to get height and width
// void	map_dim(char *filename, t_map *map)
// {
// 	int		fd;
// 	char	*line;	

// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 		exit(1);
// 	map->height = 0;
// 	line = get_next_line(fd);
// 	if (!line)
// 		exit(1);
// 	map->width = strlen(line) - 1;
// 	while (line)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 		map->height++;
// 	}
// 	close(fd);
// }

// //Read .ber and stock in map->grid
// void	map_load(char *filename, t_map *map)
// {
// 	int	fd;
// 	int	i;	

// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 		exit(1);
// 	map->grid = malloc(sizeof(char *) * (map->height + 1));
// 	if (!map->grid)
// 		exit(1);
// 	i = 0;
// 	while (i < map->height)
// 	{
// 		map->grid[i] = get_next_line(fd);
// 		i++;
// 	}
// 	map->grid[i] = NULL;
// 	close(fd);
// }
// //init map
// void	parse_map(char *filename, t_map *map)
// {
// 	map_dim(filename, map);
// 	map_load(filename, map);
// }
#include "so_long.h"

// Vérifie qu'un caractère est valide dans la map
int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'P' || c == 'E');
}

// Vérifie que tous les caractères de la map sont valides
void	check_map_characters(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == '\n')
			{
				x++;
				continue ;
			}
			if (!is_valid_char(map->grid[y][x]))
			{
				write(2, "Erreur : caractère invalide dans la map\n", 40);
				exit(1);
			}
			x++;
		}
		y++;
	}
}

// Ouvre le .ber pour obtenir la hauteur et la largeur
void	map_dim(char *filename, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(1);
	map->height = 0;
	line = get_next_line(fd);
	if (!line)
		exit(1);
	map->width = strlen(line) - 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		map->height++;
	}
	close(fd);
}

// Lit .ber et stocke chaque ligne dans map->grid
void	map_load(char *filename, t_map *map)
{
	int	fd;
	int	i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(1);
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		exit(1);
	i = 0;
	while (i < map->height)
	{
		map->grid[i] = get_next_line(fd);
		i++;
	}
	map->grid[i] = NULL;
	close(fd);
}

// Initialise la map depuis le fichier
// void	parse_map(char *filename, t_map *map)
// {
// 	map_dim(filename, map);
// 	map_load(filename, map);
// 	check_map_characters(map);
// }

void	parse_map(char *filename, t_map *map)
{
	if (!check_map_name(filename))
	{
		write(2, "Erreur : le fichier doit se terminer par .ber\n", 47);
		exit(1);
	}
	map_dim(filename, map);
	map_load(filename, map);
	check_map_characters(map);
}
