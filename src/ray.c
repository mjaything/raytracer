/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:12:52 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/03 15:12:53 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void        configure_light_source(t_env *env, t_light light)
{
    env->ray.origin = light->origin;
    env->ray.direction = normalize_vector(subtract_vector(env->ray.hit, \
                                                            light->origin));
}

// create a ray
t_ray     create_ray(t_tuple origin, t_tuple direction)
{
    t_ray ray;
    if (!is_point(origin) || !is_vector(direction))
        return NULL;
    ray.origin = origin;
    ray.direction = direction;
    return ray;
}

// compute the point at the given distance t along the ray
t_vector     find_position(t_ray ray, double time)
{
    t_vector position;
    position = ray.origin + ray.direction * time;
    return position;
}