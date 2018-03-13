/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 13:41:33 by lpilotto          #+#    #+#             */
/*   Updated: 2016/01/15 12:53:34 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.h"
#include "mlx.h"
#include "libft.h"

#include <stdio.h>

void	draw_line45_90(void *mlx, void *win, t_vectori2 *pos1, t_vectori2 *pos2)
{
	t_vectori2	d;
	int			e;

	e = pos2->y - pos1->y;
	d.y = e * 2;
	d.x = (pos2->x - pos1->x) * 2;
	while (pos1->y >= pos2->y)
	{
		mlx_pixel_put(mlx, win, pos1->x, pos1->y, 0xffffff);
		pos1->y--;
		if ((e = e + d.x) >= 0)
		{
			pos1->x++;
			e += d.y;
		}
	}
}

void	draw_line0_45(void *mlx, void *win, t_vectori2 *pos1, t_vectori2 *pos2)
{
	t_vectori2	d;
	int			e;

	e = pos2->x - pos1->x;
	d.x = e * 2;
	d.y = (pos2->y - pos1->y) * 2;
	while (pos1->x <= pos2->x)
	{
		mlx_pixel_put(mlx, win, pos1->x, pos1->y, 0xffffff);
		pos1->x++;
		if ((e = e + d.y) <= 0)
		{
			pos1->y--;
			e += d.x;
		}
	}
}

void	draw_line_45_90(void *mlx, void *win, t_vectori2 *pos1,
						t_vectori2 *pos2)
{
	t_vectori2	d;
	int			e;

	e = pos2->y - pos1->y;
	d.y = e * 2;
	d.x = (pos2->x - pos1->x) * 2;
	while (pos1->y <= pos2->y)
	{
		mlx_pixel_put(mlx, win, pos1->x, pos1->y, 0xffffff);
		pos1->y++;
		if ((e = e - d.x) <= 0)
		{
			pos1->x++;
			e += d.y;
		}
	}
}

void	draw_line_0_45(void *mlx, void *win, t_vectori2 *pos1, t_vectori2 *pos2)
{
	t_vectori2	d;
	int			e;

	e = pos2->x - pos1->x;
	d.x = e * 2;
	d.y = (pos2->y - pos1->y) * 2;
	while (pos1->x <= pos2->x)
	{
		mlx_pixel_put(mlx, win, pos1->x, pos1->y, 0xffffff);
		pos1->x++;
		if ((e = e - d.y) <= 0)
		{
			pos1->y++;
			e += d.x;
		}
	}
}

/*void	draw_line(void *mlx, void *win, t_vectori2 *pos1, t_vectori2 *pos2)
{
	t_vectori2 d;

	set_vectori2(&d, pos1->x - pos2->x, pos1->y - pos2->y);
	if (d.x <= 0)
		if (d.y > 0)
			if (ft_abs(d.x) > ft_abs(d.y))
				draw_line0_45(mlx, win, pos1, pos2);
			else
				draw_line45_90(mlx, win, pos1, pos2);
		else
			if (ft_abs(d.x) > ft_abs(d.y))
				draw_line_0_45(mlx, win, pos1, pos2);
			else
				draw_line_45_90(mlx, win, pos1, pos2);
	else
		if (d.y > 0)
			if (d.x < d.y)
				draw_line_0_45(mlx, win, pos2, pos1);
			else
				draw_line_45_90(mlx, win, pos2, pos1);
		else
			if (d.x < d.y)
				draw_line0_45(mlx, win, pos2, pos1);
			else
				draw_line45_90(mlx, win, pos2, pos1);
}*/

void	draw_line(void *mlx, void *win, t_vectori2 *pos1, t_vectori2 *pos2)
{
	t_vectori2 d;

	set_vectori2(&d, pos1->x - pos2->x, pos1->y - pos2->y);
	if (d.x <= 0)
		if (d.y > 0)
			if (ft_abs(d.x) > ft_abs(d.y))
				draw_line0_45(mlx, win, pos1, pos2);
			else
				draw_line45_90(mlx, win, pos1, pos2);
		else if (ft_abs(d.x) > ft_abs(d.y))
			draw_line_0_45(mlx, win, pos1, pos2);
		else
			draw_line_45_90(mlx, win, pos1, pos2);
	else if (d.y > 0)
		if (d.x < d.y)
			draw_line_0_45(mlx, win, pos2, pos1);
		else
			draw_line_45_90(mlx, win, pos2, pos1);
	else if (d.x < d.y)
		draw_line0_45(mlx, win, pos2, pos1);
	else
		draw_line45_90(mlx, win, pos2, pos1);
}
