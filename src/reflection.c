/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 01:40:34 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/28 01:40:35 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector    reflect_vector(t_vector input_vector, t_vector surface_normal)
{
    t_vector    reflection_vector;

    reflection_vector = subtract_vector(input_vector, \
                        multiply_vector_by_scalar(surface_normal, \
                        2 * dot_product(input_vector, surface_normal)));
    return reflection_vector;
}

t_vector    calculate_diffuse_contribution(t_env *env, t_object *object, \
                                            t_light *light)
{
    double      light_surface_normal_angle_cosine;
    t_vector    diffuse_contribution;

    light_surface_normal_angle_cosine = \
        dot_product(env->ray.direction, object->surface_normal)
    if (light_surface_normal_angle_cosine < 0)
        light_surface_normal_angle_cosine = 0;
    diffuse_contribution = multiply_vector_by_scalar(light->color, \
                                        object->material.reflection_diffuse * \
                                        light_surface_normal_angle_cosine);
    return diffuse_contribution;
}

t_vector    calculate_specular_contribution(t_env *env, t_object *object, \
                                            t_light *light)
{
    t_vector    light_vector;
    t_vector    eye_vector;
    t_vector    reflect_vector;
    double      eye_surface_normal_angle_cosine;
    double      factor;
    t_vector    specular_contribution;

    light_vector = normalize_vector(subtract_vector(light->origin, \
                                                    env->ray.hit));
    eye_vector = normalize_vector(subtract_vector(env->camera.origin, \
                                                    env->ray.hit));
    reflect_vector = normalize_vector(subtract_vector(add_vector(light_vector, \
                                                                eye_vector)));
    eye_surface_normal_angle_cosine = \
        dot_product(object->surface_normal, reflect_vector);
    factor = pow(eye_surface_normal_angle_cosine, object->material.shininess);
    specular_contribution = multiply_vector_by_scalar(light->color, \
                                        object->material.reflection_specular * \
                                        factor);
    return specular_contribution;
}