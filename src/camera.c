/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:11:49 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/25 14:11:51 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    initialize_camera(t_env *env)
{
    env->camera.origin = create_vector(0.0, 0.0, 0.0);
    env->camera.direction = create_vector(0.0, 0.0, 1.0);
    env->camera.rotation_angle = create_vector(0.0, 0.0, 0.0);
    env->camera.field_of_view = 90.0;
    env->camera.anti_aliasing = 4.0;
    env->camera.recursion_threshold = 0.0;
}

void    configure_camera(t_env *env)
{
    t_vector    vector1;
    t_vector    vector2;
    double      half_field_of_view;

    env->camera.width = env->window.width / env->window.height;
    env->camera.height = env->window.height / env->window.height;
    half_field_of_view = \
                    degree_to_radian(env->camera.field_of_view / 2.0);
    env->camera.half_view = tan(half_field_of_view);
    vector1 = multiply_vector_by_scalar(env->camera.direction, \
                                        1.0 / env->camera.half_view);
    vector2 = create_vector(0.0, env->camera.height / 2.0, 0.0);
    vector1 = add_vector(vector1, vector2);
    vector2 = create_vector(env->camera.width / 2.0, 0.0, 0.0);
    env->camera.origin = subtract_vector(vector1, vector2);
    env->camera.xi = env->camera.width / env->window.width;
    env->camera.yi = env->camera.height / env->window.height;
}