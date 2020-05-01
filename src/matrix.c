/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:25:53 by min-kim           #+#    #+#             */
/*   Updated: 2020/04/29 20:25:54 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_matrix *create_matrix(int row, int column)
{
    if (row <= 0 || column <= 0)
    {
        return NULL;
    }

    t_matrix *matrix = (t_matrix *)malloc(sizeof(t_matrix));

    matrix.row = row;
    matrix.column = column;

    matrix.value = (double *)malloc(row * column * sizeof(double));

    int i;

    i = 0;
    while (i < row * column)
    {
        matrix.data[i] = 0.0;
        i++;
    }

    return (matrix);
}

int is_same_matrix(t_matrix matrix1, t_matrix t_matrix2)
{
    if (!matrix1 || !matrix2)
    {
        return NULL;
    }
    if (matrix1.row != matrix2.row || matrix1.column != matrix2.column)
    {
        return 0;
    }
    int i;

    i = 0;
    while (i < matrix1.row * matrix1.column)
    {
        if (matrix1.data[i] != matrix2.data[2])
        {
            return 0;
        }
    }
    return 1;
}