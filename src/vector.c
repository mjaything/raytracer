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

t_vector    create_vector(double x, double y, double z)
{
    t_vector vector;

    vector.x = x;
    vector.y = y;
    vector.z = z;
    return vector;
}

t_vector     add_vector(t_vector vector1, t_vector vector2)
{
    t_vector added_vector;

    added_vector.x = vector1.x + vector2.x;
    added_vector.y = vector1.y + vector2.y;
    added_vector.z = vector1.z + vector2.z;
    return added_vector;
}

t_vector     subtract_vector(t_vector vector1, t_vector vector2)
{
    t_vector subtracted_vector;

    subtracted_vector.x = vector1.x - vector2.x;
    subtracted_vector.y = vector1.y - vector2.y;
    subtracted_vector.z = vector1.z - vector2.z;
    return subtracted_vector;
}

t_vector     negate_vector(t_vector vector)
{
    t_vector negated_vector;

    negated_vector.x = -vector.x;
    negated_vector.y = -vector.y;
    negated_vector.z = -vector.z;
    return negated_vector;
}

t_vector     multiply_vector_by_scalar(t_vector vector, double c)
{
    t_vector    multiplied_vector;

    multiplied_vector.x = c * vector.x;
    multiplied_vector.y = c * vector.y;
    multiplied_vector.z = c * vector.z;
    return multiplied_vector;
}

t_vector     divide_vector_by_scalar(t_vector vector, double c)
{
    t_vector divided_vector;

    divided_vector.x = vector.x / c;
    divided_vector.y = vector.y / c;
    divided_vector.z = vector.z / c;
    return divided_vector;
}

double      calculate_magnitude(t_vector vector)
{
    double magnitude;

    magnitude = sqrt(vector.x * vector.x + vector.y * vector.y + \
                vector.z * vector.z);
    return magnitude;
}

t_vector    normalize_vector(t_vector vector)
{
    t_vector    normalized_vector;
    double      magnitude;

    magnitude = calculate_magnitude(vector);
    normalized_vector.x = vector.x / magnitude;
    normalized_vector.y = vector.y / magnitude;
    normalized_vector.z = vector.z / magnitude; 
    return normalized_vector;
}

double      dot_product(t_tuple vector1, t_tuple vector2)
{
    return (vector1.x * vector2.x + vector1.y * vector2.y + \
            vector1.z * vector2.z);
}

t_tuple    cross_product(t_tuple vector1, t_tuple vector2)
{
    return create_vector(vector1.y * vector2.z - vector2.y * vector1.z,\
                            vector1.z * vector2.x - vector2.z * vector1.x,
                            vector1.x * vector2.y - vector2.x * vector1.y);
}

t_tuple    hadamard_product(t_tuple vector1, t_tuple vector2)
{
    return create_vector(vector1.x * vector2.x,\
                            vector1.y * vector2.y,
                            vector1.z * vector2.z);
}