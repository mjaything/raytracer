/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:38:52 by min-kim           #+#    #+#             */
/*   Updated: 2020/04/29 18:38:53 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	image_pixel_put(t_env *env, int x, int y, t_vector color_rgb)
{
	int	i;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		i = (x * (env->image.bits_per_pixel / 8)) + (y * env->image.size_line);
		env->image.image_ptr[i++] = color_rgb.z * 255;
		env->image.image_ptr[i++] = color_rgb.y * 255;
		env->image.image_ptr[i++] = color_rgb.x * 255;
		env->image.image_ptr[i] = 0;
	}
}

void	initialize_image(t_env *env)
{
	if (!(env->image.address = \
			mlx_new_image(env->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT)))
		terminate(ERROR_MLX_NEW_IMAGE);
	env->image.image_ptr = mlx_get_data_addr(env->image.address, \
											&env->image.bits_per_pixel, \
											&env->image.size_line,
											&env->image.endian);
}