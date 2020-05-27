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
    t_vector    temp_vector;

    if (object->shape == SPHERE)
    {
        temp_vector = subtract_vector(object->origin, env->ray.hit);
        object->surface_normal = normalize_vector(temp_vector);
    }
    else if (object->shape == CONE || object->shape == CYLINDER)
    {
        temp_vector = subtract_vector(object->origin, env->ray.hit);
        temp_vector = create_vector(temp_vector.x, 0.0, temp_vector.z)
        object->surface_normal = normalize_vector(temp_vector);
    }
    else if (object->shape == PLANE)
    {
        temp_vector = subtract_vector(object->origin, object->direction);
        object->surface_normal = normalize_vector(temp_vector);
    }
}