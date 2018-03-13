/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:31:15 by lpilotto          #+#    #+#             */
/*   Updated: 2016/01/12 14:52:59 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vector2.h"

void		set_vectori2(t_vectori2 *vec, int x, int y)
{
	vec->x = x;
	vec->y = y;
}

t_vectori2	*new_vectori2(int x, int y)
{
	t_vectori2 *vec;

	if ((vec = (t_vectori2 *)malloc(sizeof(t_vectori2))) == NULL)
		return (NULL);
	vec->x = x;
	vec->y = y;
	return (vec);
}
