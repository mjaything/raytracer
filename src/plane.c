/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 20:10:05 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/07 20:10:06 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double  ray_plane_intersection(t_env *env, t_object *object)
{
    double  a;
    double  b;
    double  c;
    double intersection;

    a = dot_product(object->direction, env->ray.origin);
    b = dot_product(object->direction, object->origin);
    c = dot_product(object->direction, env->ray.direction);
    intersection = -((a - b) / c);
    if (intersection < EPSILON)
        return -1.0;
    return intersection;
}