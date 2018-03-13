/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 13:11:47 by lpilotto          #+#    #+#             */
/*   Updated: 2016/01/21 15:05:34 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "matrix.h"

typedef struct s_map	t_map;
typedef struct s_point3	t_point3;

struct					s_map {
	int			size_x;
	int			size_y;
	t_point3	***map;
};

struct					s_point3 {
	int		x;
	int		y;
	int		z;
};

t_map					*create_map(int size_x, int size_y);
void					initialize_map(t_map *map);
t_map					*delete_map(t_map *map);
t_map					*realloc_map(t_map **map, int size_x, int size_y);
t_point3				*copy_point3(t_point3 *point);
t_point3				*create_point3(int x, int y, int z);
t_matrix				*to_matrix(t_point3 *point);

#endif
