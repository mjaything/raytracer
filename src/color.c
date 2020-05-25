/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 19:08:32 by min-kim           #+#    #+#             */
/*   Updated: 2020/04/29 19:08:34 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector decompose_color(int color_hex)
{
    t_vector color_rgb;

    color_rgb.x = (color_hex >> 16) & 0xFF;
    color_rgb.y = (color_hex >> 8) & 0xFF;
    color_rgb.z = (color_hex >> 0) & 0xFF;
    return color_rgb;
}