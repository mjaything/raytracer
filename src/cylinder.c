/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 20:09:59 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/07 20:10:01 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double  ray_cylinder_intersection(t_env *env, t_object *object)
{
    double      a;
    double      b;
    double      c;
    double      discriminant;
    t_vector    cylinder_to_ray_vector;

    cylinder_to_ray_vector = subtract_vector(env->ray.origin, object->origin);
    a = ft_pow(env->ray.direction.x, 2) + ft_pow(env->ray.direction.z, 2);
    b = 2 * cylinder_to_ray_vector.x * env->ray.direction.x + \
        2 * cylinder_to_ray_vector.z * env->ray.direction.z;
    c = ft_pow(cylinder_to_ray_vector.x, 2) + \
        ft_pow(cylinder_to_ray_vector.z, 2) - \
        object->scale;
    discriminant = calculate_discriminant(a, b, c);
    if (discriminant < EPSILON)
        return -1.0;
    return (-b - sqrt(discriminant)) / (2 * a);
}