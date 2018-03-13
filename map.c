/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 13:18:14 by lpilotto          #+#    #+#             */
/*   Updated: 2016/01/21 13:48:32 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map.h"

t_map	*create_map(int size_x, int size_y)
{
	t_map	*map;
	int		x;

	if ((map = (t_map *)malloc(sizeof(t_map))) == NULL)
		return (NULL);
	map->size_x = size_x;
	map->size_y = size_y;
	if ((map->map = (t_point3 ***)malloc(sizeof(t_point3 **)
		* size_x)) == NULL)
		return (delete_map(map));
	x = 0;
	while (x < size_x)
	{
		if ((map->map[x] = (t_point3 **)malloc(sizeof(t_point3 *)
			* size_y)) == NULL)
		{
			map->size_x = x;
			return (delete_map(map));
		}
		x++;
	}
	initialize_map(map);
	return (map);
}

t_map	*delete_map(t_map *map)
{
	int		x;
	int		y;

	if (!map)
		return (NULL);
	x = -1;
	if (map->map)
	{
		while (++x < map->size_x)
		{
			y = -1;
			while (++y < map->size_y)
			{
				if (map->map[x][y])
				{
					free(map->map[x][y]);
					break ;
				}
			}
			free(map->map[x]);
		}
		free(map->map);
	}
	free(map);
	return (NULL);
}

void	initialize_map(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	while (x < map->size_x)
	{
		y = 0;
		while (y < map->size_y)
		{
			map->map[x][y] = NULL;
			y++;
		}
		x++;
	}
}

t_map	*realloc_map(t_map **map, int size_x, int size_y)
{
	t_map	*tmp;
	int		x;
	int		y;

	if ((tmp = create_map(size_x, size_y)) == NULL)
		return (NULL);
	x = 0;
	while (x < tmp->size_x)
	{
		y = 0;
		while (y < tmp->size_y)
		{
			if (x < (*map)->size_x && y < (*map)->size_y)
				tmp->map[x][y] = copy_point3((*map)->map[x][y]);
			else
				tmp->map[x][y] = NULL;
			y++;
		}
		x++;
	}
	delete_map(*map);
	*map = tmp;
	return (tmp);
}
