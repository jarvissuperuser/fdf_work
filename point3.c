/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 11:53:27 by lpilotto          #+#    #+#             */
/*   Updated: 2016/01/21 14:52:31 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "matrix.h"
#include <stdlib.h>
#include <string.h>

t_point3	*copy_point3(t_point3 *point)
{
	t_point3	*copy;

	if ((copy = (t_point3 *)malloc(sizeof(t_point3))) == NULL)
		return (NULL);
	if (point)
	{
		copy->x = point->x;
		copy->y = point->y;
		copy->z = point->z;
	}
	else
	{
		copy->x = 0;
		copy->y = 0;
		copy->z = 0;
	}
	return (copy);
}

t_point3	*create_point3(int x, int y, int z)
{
	t_point3	*point;

	if ((point = (t_point3 *)malloc(sizeof(t_point3))) == NULL)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}

t_matrix	*to_matrix(t_point3 *point)
{
	t_matrix	*result;

	result = create_matrix(1, 3);
	result->matrix[0][0] = point->x;
	result->matrix[0][1] = point->y;
	result->matrix[0][2] = point->z;
	return (result);
}
