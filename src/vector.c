/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
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

t_vector     multiply_vector_by_scalar(t_vector vector, double c)
{
    t_vector    multiplied_vector;

    multiplied_vector.x = c * vector.x;
    multiplied_vector.y = c * vector.y;
    multiplied_vector.z = c * vector.z;
    return multiplied_vector;
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

double      dot_product(t_vector vector1, t_vector vector2)
{
    double number;

    number = vector1.x * vector2.x + vector1.y * vector2.y + \
            vector1.z * vector2.z; 
    return number;
}

t_vector    cross_product(t_vector vector1, t_vector vector2)
{
    t_vector resultant_vector;

    resultant_vector.x = vector1.y * vector2.z - vector2.y * vector1.z;
    resultant_vector.y = vector1.z * vector2.x - vector2.z * vector1.x;
    resultant_vector.z = vector1.x * vector2.y - vector2.x * vector1.y;
    return resultant_vector;
}

t_vector    hadamard_product(t_vector vector1, t_vector vector2)
{
    t_vector resultant_vector;

    resultant_vector.x = vector1.x * vector2.x;
    resultant_vector.y = vector1.y * vector2.y;
    resultant_vector.z = vector1.z * vector2.z;
    return resultant_vector;
}

void        clamp_vector(t_vector *vector, double min, double max)
{
    if (vector->x < min)
        vector->x = min;
    if (vector->x > max)
        vector->x = max;
    if (vector->y < min)
        vector->y = min;
    if (vector->y > max)
        vector->y = max;
    if (vector->z < min)
        vector->z = min;
    if (vector->z > max)
        vector->z = max;
}