/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:33:36 by lpilotto          #+#    #+#             */
/*   Updated: 2016/01/21 14:50:32 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP2D_H
# define MAP2D_H

# include "vector2.h"

typedef struct s_map2d	t_map2d;

struct					s_map2d {
	int			size_x;
	int			size_y;
	t_vectori2	***map;
};

t_map2d					*create_map2d(int size_x, int size_y);
void					initialize_map2d(t_map2d *map);
t_map2d					*delete_map2d(t_map2d *map);

#endif
