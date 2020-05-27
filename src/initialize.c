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
}

void    initialize_light(t_light *light)
{
    light->origin = create_vector(0.0, 0.0, 0.0);
    light->color = create_vector(0.0, 0.0, 0.0);
}

void    initialize_object(t_object *object)
{
    object->shape = SPHERE;
    object->origin = create_vector(0.0, 0.0, 0.0);
    object->direction = create_vector(0.0, 0.0, 0.0);
    object->scale = 1.0;
    object->next = NULL;
}

void    initialize_camera(t_env *env)
{
    env->camera.origin = create_vector(0.0, 0.0, 0.0);
    env->camera.direction = create_vector(0.0, 0.0, );
    env;
    env->camera.anti_aliasing = 4; // 4.0?

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