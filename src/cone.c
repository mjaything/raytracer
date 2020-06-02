/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 20:09:49 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/07 20:09:51 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double  ray_cone_intersection(t_env *env, t_object *object)
{
    double      a;
    double      b;
    double      c;
    double      discriminant;
    t_vector    cone_to_ray_vector;

    cone_to_ray_vector = subtract_vector(env->ray.origin, object->origin);
    a = ft_pow(env->ray.direction.x, 2) - ft_pow(env->ray.direction.y, 2) + \
        ft_pow(env->ray.direction.z, 2);
    b = 2 * cone_to_ray_vector.x * env->ray.direction.x - \
        2 * cone_to_ray_vector.y * env->ray.direction.y + \
        2 * cone_to_ray_vector.z * env->ray.direction.z;
    c = ft_pow(cone_to_ray_vector.x, 2) - ft_pow(cone_to_ray_vector.y, 2) + \
        ft_pow(cone_to_ray_vector.z, 2);
    discriminant = calculate_discriminant(a, b, c);
    if (discriminant < EPSILON)
        return -1.0;
    else
        return (-b - sqrt(discriminant)) / (2 * a);
}