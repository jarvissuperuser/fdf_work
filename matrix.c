/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 11:56:08 by lpilotto          #+#    #+#             */
/*   Updated: 2016/01/21 15:02:30 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdlib.h>
#include <string.h>

t_matrix	*create_matrix(int length, int height)
{
	t_matrix	*result;
	int			x;

	if ((result = (t_matrix *)malloc(sizeof(t_matrix))) == NULL)
		return (NULL);
	result->length = length;
	result->height = height;
	if ((result->matrix = (double **)malloc(sizeof(double *) * (length))) == NULL)
		return (delete_matrix(result));
	x = 0;
	while (x < length)
	{
		if ((result->matrix[x] = malloc(sizeof(double) * (height))) == NULL)
		{
			result->length = x;
			return (delete_matrix(result));
		}
		x++;
	}
	initialize_matrix(result);
	return (result);
}

void		initialize_matrix(t_matrix *matrix)
{
	int x;
	int y;

	x = 0;
	while (x < matrix->length)
	{
		y = 0;
		while (y < matrix->height)
		{
			matrix->matrix[x][y] = 0;
			y++;
		}
		x++;
	}
}

t_matrix	*delete_matrix(t_matrix *matrix)
{
	int	x;

	if (!matrix)
		return (NULL);
	x = 0;
	if (matrix->matrix)
	{
		while (x < matrix->length)
		{
			free(matrix->matrix[x]);
			x++;
		}
		free(matrix->matrix);
	}
	free(matrix);
	return (NULL);
}

t_matrix	*matrix_mult(t_matrix *a, t_matrix *b)
{
	t_matrix	*result;
	int			x;
	int			y;
	int			i;

	if (a->length != b->height ||
		(result = create_matrix(b->length, a->height)) == NULL)
		return (NULL);
	x = 0;
	while (x < result->length)
	{
		y = 0;
		while (y < result->height)
		{
			i = -1;
			while (++i < a->length)
				result->matrix[x][y] += a->matrix[i][y] * b->matrix[x][i];
			y++;
		}
		x++;
	}
	return (result);
}

t_matrix	*matrix_sum(t_matrix *a, t_matrix *b)
{
	t_matrix	*result;
	int			x;
	int			y;

	if (a->length != b->length || a->height != b->height ||
		(result = create_matrix(a->length, a->height)) == NULL)
		return (NULL);
	x = 0;
	while (x < result->length)
	{
		y = 0;
		while (y < result->height)
		{
			result->matrix[x][y] = a->matrix[x][y] + b->matrix[x][y];
			y++;
		}
		x++;
	}
	return (result);
}
