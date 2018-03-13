/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:26:19 by lpilotto          #+#    #+#             */
/*   Updated: 2016/01/21 15:05:55 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "mlx.h"
#include "line.h"
#include "vector2.h"
#include "map.h"
#include "map2d.h"
#include "env.h"
#include "libft.h"
#include "projection.h"

int		count_nullterm_char(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	parse_map_file(t_env *env, int fd)
{
	char	*line;
	char	**split;
	int		gnl;
	int		lines;
	int		i;

	line = NULL;
	lines = 0;
	while ((gnl = get_next_line(fd, &line)) == 1)
	{
		split = ft_strsplit(line, ' ');
		realloc_map(&(env->map), count_nullterm_char(split), lines + 1);
		i = 0;
		while (split[i])
		{
			if ((env->map->map[i][lines] = create_point3(i, lines, ft_atoi(split[i]))) == NULL)
			{
				delete_map(env->map);
				env->map = NULL;
				return ;
			}
			i++;
		}
		lines++;
	}
}

void	print_map(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < env->map->size_y)
	{
		x = 0;
		while (x < env->map->size_x)
		{
			ft_putnbr(env->map->map[x][y]->z);
			ft_putchar('\t');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

int		main(int argc, char **argv)
{
	t_env	*env;
	int		fd;

	if (argc != 2)
	{
		ft_putendl("Usage: ./fdf <filename>");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if ((env = (t_env *)malloc(sizeof(t_env))) == NULL)
	{
		ft_putendl("An error occured.");
		return (-1);
	}
	env->map = create_map(0, 0);
	parse_map_file(env, fd);
	env->map2d = create_map2d(env->map->size_x, env->map->size_y);
	calculate_projection(env);
	if (env->map == NULL)
	{
		free(env);
		ft_putendl("An error occured.");
		return (-1);
	}
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "fdf");
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->img_writable = mlx_get_data_addr(env->img, &(env->bits_per_pixel),
		&(env->size_line), &(env->endian));
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_loop(env->mlx);
	return (0);
}
