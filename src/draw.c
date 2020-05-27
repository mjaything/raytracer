/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:38:52 by min-kim           #+#    #+#             */
/*   Updated: 2020/04/29 18:38:53 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    image_pixel_put(t_env *env, int x, int y, t_vector color_rgb)
{
    int i;

    if (x >= 0 && x < env->window.width && y >=0 && y < env->window.height)
    {
        i = (x * env->image.bits_per_pixel / 8) + (y * env->image.size_line);
        env->image.image_ptr[i] = color_rgb.z;
        env->image.image_ptr[++i] = color_rgb.y;
        env->image.image_ptr[++i] = color_rgb.x;
        env->image.image_ptr[++i] = 0;
    }
}