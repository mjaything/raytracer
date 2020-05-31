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
                    env->j += 1.0 / env->camera.anti_aliasing;
                }
                env->i += 1.0 / env->camera.anti_aliasing;
            }
            image_pixel_put(env, env->ray.x, env->ray.y, )
            env->ray.x++;
        }
        env->ray.y++;
    }
}