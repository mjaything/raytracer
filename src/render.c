/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
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
    t_vector    reflection_ambient;
    t_vector    reflection_diffuse;
    t_vector    reflection_specular;

    light = env->light;
    env->color = create_vector(0.0, 0.0, 0.0);
    while ((light = light->next) != NULL)
    {
        configure_light_source(env, light);
        find_surface_normal(env, object);
        find_shadows(env, object, nonnegative_min_intersection, intersection);
        reflection_ambient = \
            multiply_vector_by_scalar(light->color, \
                                        object->material.reflection_ambient);
        reflection_diffuse = calculate_diffuse_contribution(env, object, light);
        reflection_specular = calculate_specular_contribution(env, object, light);
        env->color_intersection = add_vector(reflection_ambient, reflection_diffuse);
        env->color_intersection = add_vector(env->color.intersection, reflection_specular);
        env->color_intersection = multiply_vector_by_scalar(env->color_intersection, env->shadow);
        env->color_intersection = multiply_vector_by_scalar(env->color_intersection, object->material.surface_color);
        env->color = add_vector(env->color, env->color_intersection);
    }
}

void    trace_reflection(t_env *env, t_object *object)
{
    if (env->trace_recursion_depth < env->camera.recursion_threshold)
    {
        env->ray.origin = env->ray.hit;
        find_surface_normal(env, object);
        env->ray.direction = \
            reflect_vector_at_surface_noraml(env->ray.direction, \
                                            object->surface_normal);
        env->trace_recursion_depth++;
        trace_draw(env);
    }
    else
        env->trace_recursion_depth = 0;
}

void    trace_draw(t_env *env)
{
    t_object    *object;
    double      intersection;
    double      nonnegative_min_intersection;
    t_vector    position;
    t_vector    anti_aliased_color;

    nonnegative_min_intersection = INFINITY;
    object = ray_object_intersection(env, &nonnegative_min_intersection, \
                                    &intersection);
    if (object != NULL && nonnegative_min_intersection != INFINITY)
    {
        position = multiply_vector_by_scalar(env->ray.direction, \
                                            nonnegative_min_intersection);
        trace_reflection(env, object);
        trace_color(env, object, &nonnegative_min_intersection, &intersection);
    }
    else
        env->color = create_vector(0.0, 0.0, 0.0);
    anti_aliased_color = multiply_vector_by_scalar(env->color, \
                                        1 / powf(env->camera.anti_aliasing, 2));
    env->color_final = add_vector(env->color_final, anti_aliased_color);
    clamp_vector(&env->color_final, 0, 1);
}

void    trace(t_env *env)
{
    env->ray.y = 0;
    while (env->ray.y < env->window.height)
    {
        env->ray.x = 0;
        while (env->ray.x < env->window.width)
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
                    env->j += 1 / env->camera.anti_aliasing;
                }
                env->i += 1 / env->camera.anti_aliasing;
            }
            image_pixel_put(env, env->ray.x, env->ray.y, env->color_final);
            env->ray.x++;
        }
        env->ray.y++;
    }
}

void    render_scene(t_env *env)
{
    if (!(env->mlx_ptr = mlx_init()))
        terminate(ERROR_MLX_INIT);
    if (!(env->window.address = \
        mlx_new_window(env->mlx_ptr, env->window.width, env->window.height, \
                        env->arguments.scene)));
        terminate(ERROR_MLX_INIT);
    initialize_image(env);
    display_loading();
    trace(env);
}