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

t_ray       translate_ray(t_ray ray, t_matrix translation_matrix)
{
    t_ray transformed_ray;
    transformed_ray.origin.x = ray.origin.x + translation_matrix[0][4];
    transformed_ray.origin.y = ray.origin.y + translation_matrix[1][4];
    transformed_ray.origin.z = ray.origin.z + translation_matrix[2][4];
    transformed_ray.direction = ray.direction;
    return transformed_ray;
}

t_ray       scale_ray(t_ray ray, t_matrix scaling_matrix)
{
    t_ray transformed_ray;
    transformed_ray.origin.x = ray.origin.x * scaling_matrix[0][0];
    transformed_ray.origin.y = ray.origin.y * scaling_matrix[1][1];
    transformed_ray.origin.z = ray.origin.z * scaling_matrix[2][2];
    transformed_ray.direction.x = ray.direction.x * scaling_matrix[0][0];
    transformed_ray.direction.y = ray.direction.y * scaling_matrix[1][1];
    transformed_ray.direction.z = ray.direction.z * scaling_matrix[2][2];
    return transformed_ray;
}