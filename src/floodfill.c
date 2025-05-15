/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:44:49 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/15 11:46:48 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// static void	copy_map(char **src, char **dst, int h, int w)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < h)
// 	{
// 		j = 0;
// 		while (j < w && src[i][j])
// 		{
// 			dst[i][j] = src[i][j];
// 			j++;
// 		}
// 		dst[i][j] = 0;
// 		i++;
// 	}
// }

// static void	flood(char **map, int x, int y, t_dim dim)
// {
// 	if (x < 0 || y < 0 || x >= dim.w || y >= dim.h)
// 		return ;
// 	if (map[y][x] == '1' || map[y][x] == 'F')
// 		return ;
// 	map[y][x] = 'F';
// 	flood(map, x + 1, y, dim);
// 	flood(map, x - 1, y, dim);
// 	flood(map, x, y + 1, dim);
// 	flood(map, x, y - 1, dim);
// }

// static int	check_path(char **map, int h)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < h)
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == 'C' || map[i][j] == 'E')
// 				return (0);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// static char	**allocate_map(int h, int w)
// {
// 	char	**map;
// 	int		i;

// 	map = malloc(sizeof(char *) * (h + 1));
// 	if (!map)
// 		return (NULL);
// 	i = 0;
// 	while (i < h)
// 	{
// 		map[i] = malloc(w + 1);
// 		if (!map[i])
// 			return (NULL);
// 		i++;
// 	}
// 	map[i] = NULL;
// 	return (map);
// }

// int	is_valid_path(char **map, int x, int y, t_dim dim)
// {
// 	char	**tmp;
// 	int		i;
// 	int		res;

// 	tmp = allocate_map(dim.h, dim.w);
// 	if (!tmp)
// 		return (0);
// 	copy_map(map, tmp, dim.h, dim.w);
// 	flood(tmp, x, y, dim);
// 	res = check_path(tmp, dim.h);
// 	i = 0;
// 	while (i < dim.h)
// 	{
// 		free(tmp[i]);
// 		i++;
// 	}
// 	free(tmp);
// 	return (res);
// }

#include "so_long.h"

static char	**allocate_map(int h, int w)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (h + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < h)
	{
		map[i] = malloc(sizeof(char) * (w + 1));
		if (!map[i])
			return (NULL);
		i++;
	}
	map[i] = NULL;
	return (map);
}

static void	copy_map(char **src, char **dst, int h, int w)
{
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			dst[i][j] = src[i][j];
			j++;
		}
		dst[i][j] = '\0';
		i++;
	}
}

static void	flood(char **map, int x, int y, t_dim dim)
{
	if (x < 0 || y < 0 || x >= dim.w || y >= dim.h)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood(map, x + 1, y, dim);
	flood(map, x - 1, y, dim);
	flood(map, x, y + 1, dim);
	flood(map, x, y - 1, dim);
}

static int	all_c_and_e_reachable(char **map, t_map *data, t_dim dim)
{
	char	**copy;
	int		i;
	int		reachable;
	int		ex_x;
	int		ex_y;

	copy = allocate_map(dim.h, dim.w);
	if (!copy)
		return (0);
	copy_map(map, copy, dim.h, dim.w);
	flood(copy, data->player_x, data->player_y, dim);
	reachable = 1;
	ex_x = data->exit_x;
	ex_y = data->exit_y;
	if (copy[ex_y][ex_x] != 'F')
		reachable = 0;
	i = 0;
	while (i < dim.h && reachable)
	{
		if (ft_strchr(copy[i], 'C'))
			reachable = 0;
		i++;
	}
	free_map_struct(copy, dim.h);
	return (reachable);
}

int	is_valid_path(char **map, int x, int y, t_dim dim)
{
	t_map	data;

	data.grid = map;
	data.player_x = x;
	data.player_y = y;
	data.exit_x = -1;
	data.exit_y = -1;
	data.height = dim.h;
	data.width = dim.w;
	while (++y < dim.h)
	{
		x = -1;
		while (++x < dim.w)
		{
			if (map[y][x] == 'E')
			{
				data.exit_x = x;
				data.exit_y = y;
				break ;
			}
		}
	}
	if (data.exit_x == -1)
		return (0);
	return (all_c_and_e_reachable(map, &data, dim));
}
