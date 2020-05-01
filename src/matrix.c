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
    while (i < row * column)
    {
        matrix.data[i] = 0.0;
        i++;
    }

    return (matrix);
}