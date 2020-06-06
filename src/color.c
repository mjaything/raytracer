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

    color_rgb.x = (color_hex >> 16) % 256 / 255.0;
    color_rgb.y = (color_hex >> 8) % 256 / 255.0;
    color_rgb.z = (color_hex >> 0) % 256 / 255.0;
    return color_rgb;
}

t_vector    parse_color(char *line)
{
    int         color_hex;
    t_vector    color_rgb;

    color_hex = ft_atoi_base(line, 16);
    color_rgb = decompose_color(color_hex);
    return color_rgb;
}