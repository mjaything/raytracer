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

t_tuple separate_rgb_components(int color)
{
    t_tuple rgb_components;

    rgb_components.x = (color >> 16) & 0xFF;
    rgb_components.y = (color >> 8) & 0xFF;
    rgb_components.z = (color >> 0) & 0xFF;

    return (rgb_component);
}