/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:44:49 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/13 16:13:27 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// static void	copy_map(char **src, char **dst, int h)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < h)
// 	{
// 		j = 0;
// 		while (src[i][j])
// 		{
// 			dst[i][j] = src[i][j];
// 			j++;
// 		}
// 		dst[i][j] = 0;
// 		i++;
// 	}
// }

// static void	flood(char **map, int x, int y, int w, int h)
// {
// 	if (x < 0 || y < 0 || x >= w || y >= h)
// 		return ;
// 	if (map[y][x] == '1' || map[y][x] == 'F')
// 		return ;
// 	map[y][x] = 'F';
// 	flood(map, x + 1, y, w, h);
// 	flood(map, x - 1, y, w, h);
// 	flood(map, x, y + 1, w, h);
// 	flood(map, x, y - 1, w, h);
// }

// static int	check_path(char **map, int h)
// {
// 	int	i = 0;
// 	int	j;

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

// // map : map d'origine, x/y joueur, w/h taille map
// int	is_valid_path(char **map, int x, int y, int w, int h)
// {
// 	char	**tmp;
// 	int		i;
// 	int		res;

// 	tmp = malloc(sizeof(char *) * (h + 1));
// 	if (!tmp)
// 		return (0);
// 	i = 0;
// 	while (i < h)
// 	{
// 		tmp[i] = malloc(w + 1);
// 		if (!tmp[i])
// 			return (0);
// 		i++;
// 	}
// 	copy_map(map, tmp, h);
// 	flood(tmp, x, y, w, h);
// 	res = check_path(tmp, h);
// 	i = 0;
// 	while (i < h)
// 		free(tmp[i++]);
// 	free(tmp);
// 	return (res);
// }

#include "so_long.h"

static void	copy_map(char **src, char **dst, int h, int w)
{
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w && src[i][j])
		{
			dst[i][j] = src[i][j];
			j++;
		}
		dst[i][j] = 0;
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

static int	check_path(char **map, int h)
{
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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
		map[i] = malloc(w + 1);
		if (!map[i])
			return (NULL);
		i++;
	}
	map[i] = NULL;
	return (map);
}

// int	is_valid_path(char **map, int x, int y, int w, int h)
// {
// 	t_dim	dim;
// 	char	**tmp;
// 	int		i;
// 	int		res;

// 	dim.w = w;
// 	dim.h = h;
// 	tmp = allocate_map(h, w);
// 	if (!tmp)
// 		return (0);
// 	copy_map(map, tmp, h);
// 	flood(tmp, x, y, dim);
// 	res = check_path(tmp, h);
// 	i = 0;
// 	while (i < h)
// 	{
// 		free(tmp[i]);
// 		i++;
// 	}
// 	free(tmp);
// 	return (res);
// }

int	is_valid_path(char **map, int x, int y, t_dim dim)
{
	char	**tmp;
	int		i;
	int		res;

	tmp = allocate_map(dim.h, dim.w);
	if (!tmp)
		return (0);
	copy_map(map, tmp, dim.h, dim.w);
	flood(tmp, x, y, dim);
	res = check_path(tmp, dim.h);
	i = 0;
	while (i < dim.h)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	return (res);
}
