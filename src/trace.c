/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 16:24:11 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/31 16:24:12 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    trace_color(t_env *env, t_object *object, \
                    double *nonnegative_min_intersection, double *intersection)
{
    t_light     *light;

    light = env->light;
    env->color = create_vector(0.0, 0.0, 0.0);
    while ((light = light->next) != NULL)
    {
        configure_light_source(env, light);
        find_surface_normal(env, object);
        find_shadows(env, object, nonnegative_min_intersection, intersection);
        light->attenuation = 1.0 / (light->constant + light->linear * \
            *nonnegative_min_intersection + light->quadratic * \
            (*nonnegative_min_intersection * *nonnegative_min_intersection));
        env->color_intersection = add_vector(multiply_vector_by_scalar\
            (light->color, object->material.reflection_ambient), \
            add_vector(calculate_diffuse_contribution(env, object, light), \
            calculate_specular_contribution(env, object, light)));
        env->color_intersection = multiply_vector_by_scalar\
                                (env->color_intersection, light->attenuation);
        env->color_intersection = \
            multiply_vector_by_scalar(env->color_intersection, env->shadow);
        env->color_intersection = hadamard_product(env->color_intersection, \
                                        object->material.surface_color);
        env->color = add_vector(env->color, env->color_intersection);
    }
}

void    trace_draw(t_env *env)
{
    t_object    *object;
    t_vector    position;
    t_vector    anti_aliased_color;
    double      intersection;
    double      nonnegative_min_intersection;

    nonnegative_min_intersection = INFINITY;
    object = ray_object_intersection(env, &nonnegative_min_intersection, \
                                    &intersection);
    if (object != NULL && nonnegative_min_intersection != INFINITY)
    {
        position = multiply_vector_by_scalar(env->ray.direction, \
                                            nonnegative_min_intersection);
        env->ray.hit = add_vector(env->ray.origin, position);
        trace_color(env, object, &nonnegative_min_intersection, &intersection);
    }
    else
        env->color = create_vector(0.0, 0.0, 0.0);
    anti_aliased_color = multiply_vector_by_scalar(env->color, \
                                        1 / powf(env->camera.anti_aliasing, 2));
    env->color_final = add_vector(env->color_final, anti_aliased_color);
    clamp_vector(&env->color_final, 0, 1);
}

void    initialize_trace(t_env *env)
{

    t_vector    vector1;
    t_vector    vector2;
    
    env->ray.origin = env->camera.position;
    env->ray.direction = env->camera.origin;
    env->ray.hit = create_vector(0.0, 0.0, 0.0);
    vector1 = create_vector(env->camera.xi * env->i, 0.0, 0.0);
    vector2 = create_vector(0.0, env->camera.yi * env->j, 0.0);
    vector1 = subtract_vector(vector1, vector2);
    env->ray.direction = add_vector(env->camera.origin, vector1);
    rotate_vector(&env->ray.direction, env->camera.rotation_angle);
    env->ray.direction = normalize_vector(env->ray.direction);
}

void    trace(t_env *env)
{
    env->ray.y = 0;
    while (env->ray.y < WINDOW_HEIGHT)
    {
        env->ray.x = 0;
        while (env->ray.x < WINDOW_WIDTH)
        {
            env->color_final = create_vector(0.0, 0.0, 0.0);
            env->i = env->ray.x;
            while (env->i < env->ray.x + 1.0)
            {
                env->j = env->ray.y;
                while (env->j < env->ray.y + 1.0)
                {
                    initialize_trace(env);
                    trace_draw(env);
                    env->j += (1 / env->camera.anti_aliasing);
                }
                env->i += (1 / env->camera.anti_aliasing);
            }
            image_pixel_put(env, env->ray.x, env->ray.y, env->color_final);
            env->ray.x++;
        }
        env->ray.y++;
    }
}