/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:04:13 by lleichtn          #+#    #+#             */
/*   Updated: 2025/02/26 13:48:45 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_map_enclosed(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->width)
	{
		if (map->grid[0][x] != '1' || map->grid[map->height - 1][x] != '1')
		{
			exit(1);
		}
		x++;
	}
	y = 0;
	while (y < map->height)
	{
		if (map->grid[y][0] != '1' || map->grid[y][map->width - 1] != '1')
		{
			exit(1);
		}
		y++;
	}
	if (map->width == map->height)
		exit(1);
}

void	count_elements(t_map *map, int *player, int *ex, int *collectibles)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'P')
			{
				(*player)++;
				map->player_x = x;
				map->player_y = y;
			}
			else if (map->grid[y][x] == 'E')
				(*ex)++;
			else if (map->grid[y][x] == 'C')
				(*collectibles)++;
			x++;
		}
		y++;
	}
}

void	has_required_elements(t_map *map)
{
	int	player;
	int	ex;
	int	collectibles;

	player = 0;
	ex = 0;
	collectibles = 0;
	count_elements(map, &player, &ex, &collectibles);
	if (player != 1 || ex != 1 || collectibles < 1)
		exit(1);
	map->collectibles = collectibles;
}

void	check_map_validity(t_map *map)
{
	is_map_enclosed(map);
	has_required_elements(map);
}
