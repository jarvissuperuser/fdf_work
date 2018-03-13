/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 12:01:14 by lpilotto          #+#    #+#             */
/*   Updated: 2016/01/20 13:25:23 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

typedef struct s_matrix	t_matrix;

struct					s_matrix {
	int		length;
	int		height;
	double	**matrix;
};

t_matrix	*create_matrix(int length, int height);
void		initialize_matrix(t_matrix *matrix);
t_matrix	*delete_matrix(t_matrix *matrix);
t_matrix	*matrix_mult(t_matrix *a, t_matrix *b);
t_matrix	*matrix_sum(t_matrix *a, t_matrix *b);

#endif
