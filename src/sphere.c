/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 20:09:35 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/07 20:09:37 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double  ray_sphere_intersection(t_env *env, t_object *object)
{
    double      a;
    double      b;
    double      c;
    double      discriminant;
    t_vector    sphere_to_ray_vector;

    sphere_to_ray_vector = subtract_vector(env->ray.origin, object->origin);
    a = dot_product(env->ray.direction, env->ray.direction);
    b = 2 * dot_product(sphere_to_ray_vector, env->ray.direction);
    c = dot_product(sphere_to_ray_vector, sphere_to_ray_vector) - object->scale;
    discriminant = calculate_discriminant(a, b, c);
    if (discriminant < EPSILON)
        return -1.0;
    else
        return (-b - sqrt(discriminant)) / (2 * a);
}