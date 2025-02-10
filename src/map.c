/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:04:03 by lleichtn          #+#    #+#             */
/*   Updated: 2025/02/10 15:15:07 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Opem .ber to get height and width
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

//Read .ber and stock in map->grid
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

//init map
void	parse_map(char *filename, t_map *map)
{
	map_dim(filename, map);
	map_load(filename, map);
}
