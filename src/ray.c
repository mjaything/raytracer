/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:12:52 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/03 15:12:53 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray     create_ray(t_tuple origin, t_tuple direction)
{
    t_ray ray;
    if (!is_point(origin) || !is_vector(direction))
        return NULL;
    ray.origin = origin;
    ray.direction = direction;
    return ray;
}

t_tuple     find_position(t_ray ray, double distance)
{
    t_tuple position;
    position = ray.origin + ray.direction * distance;
    return position;
}