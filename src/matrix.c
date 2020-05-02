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
        return NULL;
    t_matrix *matrix = (t_matrix *)malloc(sizeof(t_matrix));
    matrix->row = row;
    matrix->column = column;
    matrix->value = (double *)malloc(row * column * sizeof(double));

    int i;

    i = 0;
    while (i < row * column)
    {
        matrix->value[i] = 0.0;
        i++;
    }
    return (matrix);
}

int set_element(t_matrix *matrix, int row, int column, double value)
{
    if (!matrix)
        return -1;
    if (row <= 0 || column <= 0 || row > matrix->row || col > matrix->column)
        return -1;
    ELEMENT(matrix, row, column) = value;
    return 0;
}

int is_same_matrix(t_matrix *matrix1, t_matrix *matrix2)
{
    if (!matrix1 || !matrix2)
        return -1;
    if (matrix1->row != matrix2->row || matrix1->column != matrix2->column)
        return -1;

    int i;
    int j;

    i = 0;
    while (i < matrix1->row)
    {
        j = 0;
        while (j < matrix1->column)
        {
            if (ELEMENT(matrix1, i + 1, j + 1) != \
                ELEMENT(matrix2, i + 1, j + 1))
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

int multiply_matrix_helper(t_matrix *matrix1, t_matrix *matrix2, int i, int j)
{
    int k;
    int value;

    k = 0;
    while (k < matrix1->column)
    {
        value += ELEMENT(matrix1, i + 1, k + 1) * \
                ELEMENT(matrix2, k + 1, j + 1);
        k++;
    }
    return value;
}

int multiply_matrix(t_matrix *matrix1, t_matrix *matrix2)
{
    if (!matrix1 || !matrix2)
        return NULL;

    t_matrix *result_matrix;
    result_matrix = create_matrix(matrix1->row, matrix2->column);

    int i;
    int j;

    i = 0;
    while (i < result_matrix->row)
    {
        j = 0;
        while (j < result_matrix->column)
        {
            ELEMENT(result_matrix, i + 1, j + 1) = \
            matrix_multiplication_helper(matrix1, matrix2, i, j);
            j++;
        }
        i++;
    }
}

t_matrix *create_identity_matrix(int row, int column)
{
    if (row <= 0 || column <= 0)
        return NULL;

    t_matrix *matrix;
    matrix = create_matrix(row, column);

    int i;
    int j;

    i = 0;
    while (i < row)
    {
        j = 0;
        while (j < column)
        {
            if (row == column)
                ELEMENT(matrix, i + 1, j + 1) = 1;
            else
                ELEMENT(matrix, i + 1, j + 1) = 0;
            j++;
        }
        i++;
    }
    return matrix;
}

t_matrix *create_transposed_matrix(t_matrix *matrix)
{
    if (!matrix)
        return NULL;

    t_matrix *transposed_matrix;
    transposed_matrix = create_matrix(matrix->column, matrix->row);

    int i;
    int j;

    i = 0;
    while (i < matrix->column)
    {
        while (j < matrix->row)
        {
            ELEMENT(transposed_matrix, i + 1, j + 1) = \
            ELEMENT(matrix, j + 1, i + 1);
            j++;
        }
        i++;
    }
    return transposed_matrix;
}

int calculate_determinant_2x2(t_matrix *matrix)
{
    if (matrix->row != 2 || matrix->column != 2)
        return NULL;

    int determinant;

    determinant = ELEMENT(matrix, 1, 1) * ELEMENT(matrix, 2, 2) - \
                    ELEMENT(matrix, 1, 2) * ELEMENT(matrix, 2, 1);
    return (determinant);
}

t_matrix *create_submatrix(t_matrix *matrix, int i, int j)
{
    if (row <= 0 || column <= 0)
        return NULL;

    t_matrix *submatrix;
    submatrix = create_matrix(matrix->row - 1, matrix->column - 1);

    int k;
    int l;
    int m;
    int n;

    k = 0;
    while (k < submatrix->row)
    {
        m =  = (k >= i ? k + 1 : k);
        l = 0;
        while (l < submatrix->column)
        {
            n = (l >= j ? l + 1 : l);
            ELEMENT(submatrix, k + 1, l + 1) = ELEMENT(matrix, m + 1, n + 1);
            l++;
        }
        k++;
    }
    return submatrix;
}

int calculate_minor_3x3(t_matrix *matrix, int i, int j)
{
    if (matrix->row != 3 || matrix->column != 3)
        return NULL;

    int minor;

    t_matrix *submatrix = (t_matrix *)malloc(sizeof(t_matrix));
    submatrix = create_submatrix(matrix, i, j);
    minor = calculate_determinant_2x2(submatrix);

    return (minor);
}

int calculate_cofactor(t_matrix *matrix, int i, int j)
{
    int minor;
    int cofactor;

    minor = calculate_minor_3x3(matrix, i, j);
    if (i == 0 && j == 1 || i == 1 && j == 0 || 
        i == 1 && j == 2 || i == 2 && j == 1)
        cofactor = -minor;
    else
        cofactor = minor;

    return (cofactor);
}

int calculate_determinant(t_matrix *matrix)
{
    int determinant;
    int i;
    
    determinant = 0;
    i = 0;
    while (i < matrix->column)
    {
        determinant += ELEMENT(matrix, 1, i + 1) * \
                        calculate_cofactor(matrix, 0, i);
        i++;
    }

    return determinant;
}

t_matrix *create_cofactor_matrix(t_matrix *matrix)
{
    if (!matrix)
        return NULL;

    t_matrix *cofactor_matrix;
    cofactor_matrix = create_matrix(matrix->row, matrix->column);

    int i;
    int j;

    i = 0;
    while (i < matrix->row)
    {
        j = 0;
        while (j < matrix->column)
        {
            ELEMENT(cofactor_matrix, i + 1, j + 1) = \
                calculate_cofactor(matrix, i, j);
            j++;
        }
        i++;
    }
    return cofactor_matrix;
}

t_matrix *create_inversion_matrix(t_matrix *matrix)
{
    if (!matrix)
        return NULL;
    int determinant = calculate_determinant(matrix)
    if (determinant == 0)
        return NULL;

    t_matrix *inversion_matrix;
    inversion_matrix = create_cofactor_matrix(matrix);
    inversion_matrix = create_transposed_matrix(inversion_matrix);

    int i;
    int j;

    i = 0;
    while (i < cofactor_matrix->row)
    {
        j = 0;
        while (j < cofactor_matrix->column)
        {
            ELEMENT(inversion_matrix, i + 1, j + 1) /= determinant;
            j++;
        }
        i++;
    }
    return inversion_matrix;
}

t_matrix *create_translation_matrix(double x, double y, double z)
{
    t_matrix *translation_matrix;
    translation_matrix = create_identity_matrix(4, 4);
    set_element(translation_matrix, 1, 4, x);
    set_element(translation_matrix, 2, 4, y);
    set_element(translation_matrix, 3, 4, z);
    return translation_matrix;
}

t_matrix *create_scaling_matrix(double x, double y, double z)
{
    t_matrix *scaling_matrix;
    scaling_matrix = create_identity_matrix(4, 4);
    set_element(scaling_matrix, 1, 1, x);
    set_element(scaling_matrix, 2, 2, y);
    set_element(scaling_matrix, 3, 3, z);
    return scaling_matrix;
}

t_matrix *create_rotation_matrix_x(double radian)
{
    t_matrix *rotation_matrix_x;
    rotation_matrix_x = create_identity_matrix(4, 4);
    set_element(rotation_matrix_x, 2, 2, cos(radian));
    set_element(rotation_matrix_x, 2, 3, -sin(radian));
    set_element(rotation_matrix_x, 3, 2, sin(radian));
    set_element(rotation_matrix_x, 3, 3, cos(radian));
    return rotation_matrix_x;
}

t_matrix *create_rotation_matrix_y(double radian)
{
    t_matrix *rotation_matrix_y;
    rotation_matrix_y = create_identity_matrix(4, 4);
    set_element(rotation_matrix_y, 1, 1, cos(radian));
    set_element(rotation_matrix_y, 1, 3, sin(radian));
    set_element(rotation_matrix_y, 3, 1, -sin(radian));
    set_element(rotation_matrix_y, 3, 3, cos(radian));
    return rotation_matrix_y;
}

t_matrix *create_rotation_matrix_z(double radian)
{
    t_matrix *rotation_matrix_z;
    rotation_matrix_z = create_identity_matrix(4, 4);
    set_element(rotation_matrix_z, 1, 1, cos(radian));
    set_element(rotation_matrix_z, 1, 2, -sin(radian));
    set_element(rotation_matrix_z, 2, 1, sin(radian));
    set_element(rotation_matrix_z, 2, 2, cos(radian));
    return rotation_matrix_z;
}

t_matrix *create_shearing_matrix(double xy, double xz, double yx, double yz, \
                                double zx, double zy)
{
    t_matrix *shearing_matrix;
    shearing_matrix = create_identity_matrix(4, 4);
    set_element(shearing_matrix, 1, 2, xy);
    set_element(shearing_matrix, 1, 3, xz);
    set_element(shearing_matrix, 2, 1, yx);
    set_element(shearing_matrix, 2, 3, yz);
    set_element(shearing_matrix, 3, 1, zx);
    set_element(shearing_matrix, 3, 2, zy);
    return shearing_matrix;
}