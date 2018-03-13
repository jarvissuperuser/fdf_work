/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:38:56 by lpilotto          #+#    #+#             */
/*   Updated: 2016/01/21 14:58:17 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map2d.h"
#include "matrix.h"
#include "vector2.h"
#include "map.h"
#include "env.h"

t_map2d	*create_map2d(int size_x, int size_y)
{
	t_map2d *map;
	int		x;

	if ((map = (t_map2d *)malloc(sizeof(t_map2d))) == NULL)
		return (NULL);
	map->size_x = size_x;
	map->size_y = size_y;
	if ((map->map = (t_vectori2 ***)malloc(sizeof(t_vectori2 **)
		* size_x)) == NULL)
		return (delete_map2d(map));
	x = 0;
	while (x < size_x)
	{
		if ((map->map[x] = (t_vectori2 **)malloc(sizeof(t_vectori2 *)
			* size_y)) == NULL)
		{
			map->size_x = x;
			return (delete_map2d(map));
		}
		x++;
	}
	initialize_map2d(map);
	return (map);
}

t_map2d	*delete_map2d(t_map2d *map)
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
			while (++y < map-> size_y)
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

void	initialize_map2d(t_map2d *map)
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

void	calculate_projection(t_env *env)
{
	int			x;
	int			y;
	t_matrix	*tmp;
	t_matrix	*tmp2;
	t_matrix	*matrix_point;

	tmp = create_matrix(3, 2);
	tmp->matrix[0][0] = 1;
	tmp->matrix[2][1] = 1;
	x = 0;
	while (x < env->map2d->size_x)
	{
		y = 0;
		while (y < env->map2d->size_y)
		{
			matrix_point = to_matrix(env->map->map[x][y]);
			tmp2 = matrix_mult(tmp, matrix_point);
			env->map2d->map[x][y] = new_vectori2(tmp2->matrix[0][0], tmp2->matrix[0][1]);
			delete_matrix(matrix_point);
			delete_matrix(tmp2);
			y++;
		}
		x++;
	}
	delete_matrix(tmp);
}
