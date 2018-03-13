/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:15:56 by lpilotto          #+#    #+#             */
/*   Updated: 2016/01/12 14:37:35 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "vector2.h"

void	draw_line(void *mlx, void *win, t_vectori2 *pos1, t_vectori2 *pos2);

#endif
