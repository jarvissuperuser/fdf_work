/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 13:43:40 by lpilotto          #+#    #+#             */
/*   Updated: 2016/01/21 19:57:00 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H

typedef	struct s_vectori2	t_vectori2;

struct						s_vectori2
{
		int	x;
		int	y;
};

t_vectori2					*new_vectori2(int x, int y);
void						set_vectori2(t_vectori2 *vec, int x, int y);

#endif
