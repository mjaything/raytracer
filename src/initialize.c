/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 19:46:16 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/22 19:46:17 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    initialize_environment(t_env *env)
{
    t_light     *light;
    t_object    *object;

    if (!(light = (t_light *)malloc(sizeof(t_light))) ||
        !(object = (t_object *)malloc(sizeof(t_object))))
        terminate(ERROR_ENVIRONMENT_INITIALIZATION);
    env->light = light;
    env->light->next = NULL;
    env->object = object;
    env->object->next = NULL;
    env->window.width = WINDOW_WIDTH;
    env->window.height = WINDOW_HEIGHT;
    env->trace_recursion_depth = 0;
    env->shadow = 1.0;
    env->intersection[0] = ray_sphere_intersection;
    env->intersection[1] = ray_cone_intersection;
    env->intersection[2] = ray_cylinder_intersection;
    env->intersection[3] = ray_plane_intersection;
}

void    initialize_light(t_light *light)
{
    light->origin = create_vector(0.0, 0.0, 0.0);
    light->color = create_vector(0.0, 0.0, 0.0);
    light->intensity = 1.0;
}

void    initialize_object(t_object *object)
{
    object->shape = SPHERE;
    object->origin = create_vector(0.0, 0.0, 0.0);
    object->direction = create_vector(0.0, 0.0, 0.0);
    object->scale = 1.0;
    object->next = NULL;
}

void    initialize_material(t_material *material)
{
    material->surface_color = create_vector(1.0, 1.0, 1.0);
    material->reflection_ambient = 0.0;
    material->reflection_diffuse = 0.0;
    material->reflection_specular = 0.0;
    material->shininess = 0.0;
}

void    initialize_image(t_env *env)
{
    if (!(env->image.address = mlx_new_image(env->mlx_ptr, env->window.width, \
                                                env->window.height)))
        terminate(ERROR_MLX_NEW_IMAGE);
    env->image.image_ptr = mlx_get_data_addr(env->image.address, \
                                            &env->image.bits_per_pixel, \
                                            &env->image.size_line,
                                            &env->image.endian);
}

void    initialize_trace(t_env *env)
{
    t_vector    vector1;
    t_vector    vector2;

    env->trace_recursion_depth = 0.0;
    env->ray.hit = create_vector(0.0, 0.0, 0.0);
    env->ray.origin = env->camera.position;
    env->direction = env->camera.origin;
    vector1 = create_vector(env->camera.xi * env->i, 0.0, 0.0);
    vector2 = create_vector(0.0, env->camera.yi * env->j, 0.0);
    vector1 = subtract_vector(vector1, vector2);
    env->ray.direction = add_vector(env->camera.origin, vector1);
    rotate(&env->camera.origin, &env->camera.rotation_angle);
    env->ray.direction = normalize(env->ray.direction);
}