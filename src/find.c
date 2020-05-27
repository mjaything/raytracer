/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 17:43:54 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/23 17:43:56 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    find_surface_normal(t_env *env, t_object *object)
{
    t_vector    surface_normal;

    if (object->shape == SPHERE)
    {
        surface_normal = subtract_vector(object->origin, env->ray.hit);
        object->surface_normal = normalize_vector(surface_normal);
    }
    else if (object->shape == CONE || object->shape == CYLINDER)
    {
        surface_normal = subtract_vector(object->origin, env->ray.hit);
        surface_normal.y = 0.0;
        object->surface_normal = normalize_vector(surface_normal);
    }
    else if (object->shape == PLANE)
    {
        surface_normal = subtract_vector(object->origin, object->direction);
        object->surface_normal = normalize_vector(surface_normal);
    }
}