/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 13:01:40 by lpilotto          #+#    #+#             */
/*   Updated: 2016/01/21 14:45:59 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# define WIDTH 600
# define HEIGHT 600
# include "map.h"
# include "map2d.h"

typedef struct s_env	t_env;

struct					s_env {
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_writable;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	double	rotx;
	double	roty;
	double	rotz;
	double	zoom;
	t_map	*map;
	t_map2d	*map2d;
};

#endif
