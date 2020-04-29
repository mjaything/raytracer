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

t_vector    add_vector(t_vector v1, t_vector v2)
{
    t_vector v;

    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    v.z = v1.z + v2.z;

    return (v);
}

t_vector    subtract_vector(t_vector v1, t_vector v2)
{
    t_vector v;

    v.x = v1.x - v2.x;
    v.y = v1.y - v2.y;
    v.z = v1.z - v2.z;

    return (v);
}

t_vector    negate_vector(t_vector v1)
{
    t_vector v;

    v.x = -v1.x;
    v.y = -v1.y;
    v.z = -v1.z;

    return (v);
}

t_vector    multiply_vector_by_scalar(t_vector v1, double c)
{
    t_vector v;

    v.x = c * v1.x;
    v.y = c * v1.y;
    v.z = c * v1.z;

    return (v);
}

t_vector    divide_vector_by_scalar(t_vector v1, double c)
{
    t_vector v;

    v.x = v1.x / c;
    v.y = v1.y / c;
    v.z = v1.z / c;

    return (v);
}

t_vector    cross_product(t_vector v1, t_vector v2)
{
    t_vector v;

    v.x = v1.y * v2.z - v2.y * v1.z;
    v.y = v1.z * v2.x - v2.z * v1.x;
    v.z = v1.x * v2.y - v2.x * v1.y;

    return (v);
}