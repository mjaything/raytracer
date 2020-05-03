/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 04:32:36 by min-kim           #+#    #+#             */
/*   Updated: 2020/04/29 04:32:38 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_tuple     create_tuple(double x, double y, double z, double w)
{
    t_tuple tuple;
    tuple.x = x;
    tuple.y = y;
    tuple.z = z;
    tuple.w = w;
    return tuple;
}

t_tuple     create_point(double x, double y, double z)
{
    return create_tuple(x, y, z, 1.0);
}

t_tuple     create_vector(double x, double y, double z)
{
    return create_tuple(x, y, z, 0.0);
}

int         is_point(t_tuple point)
{
    if (point.w == 1.0)
        return 1;
    else
        return 0;
}

int         is_vector(t_tuple vector)
{
    if (vector.w == 0.0)
        return 1;
    else
        return 0;
}

t_tuple     add_vector(t_tuple vector1, t_tuple vector2)
{
    return create_vector(vector1.x + vector2.x, vector1.y + vector2.y, \
                            vector1.z + vector2.z);
}

t_tuple     subtract_vector(t_tuple vector1, t_tuple vector2)
{
    return create_vector(vector1.x - vector2.x, vector1.y - vector2.y, \
                            vector1.z + vector2.z);
}

t_tuple     negate_vector(t_tuple vector)
{
    return create_vector(-vector.x, -vector.y, -vector.z);
}

t_tuple     multiply_vector_by_scalar(t_tuple vector, double c)
{
    return create_vector(c * vector.x, c * vector.y, c * vector.z);
}

t_tuple     divide_vector_by_scalar(t_tuple vector, double c)
{
    return create_vector(vector.x / c, vector.y / c, vector.z / c);
}

double      calculate_magnitude(t_tuple vector)
{
    return (sqrt(vector.x * vector.x + vector.y * vector.y + \
                vector.z * vector.z));
}

t_vector    normalize(t_tuple vector)
{
    double magnitude;

    magnitude = calculate_magnitude(v);
    return create_vector(vector.x / magnitude, vector.y / magnitude, \
                            vector.z / magnitude);
}

double      dot_product(t_tuple vector1, t_tuple vector2)
{
    return (vector1.x * vector2.x + vector1.y * vector2.y + \
            vector1.z * vector2.z);
}

t_vector    cross_product(t_tuple vector1, t_tuple vector2)
{
    return create_vector(vector1.y * vector2.z - vector2.y * vector1.z,\
                            vector1.z * vector2.x - vector2.z * vector1.x,
                            vector1.x * vector2.y - vector2.x * vector1.y);
}

t_vector    hadamard_product(t_tuple vector1, t_tuple vector2)
{
    return create_vector(vector1.x * vector2.x,\
                            vector1.y * vector2.y,
                            vector1.z * vector2.z);
}