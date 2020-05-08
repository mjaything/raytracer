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

double  *ray_sphere_intersection(t_object sphere, t_ray ray)
{
    t_tuple sphere_to_ray_vector;
    double  a;
    double  b;
    double  c;
    double  discriminant;
    double  intersection1;
    double  intersection2;
    double  intersections[2];
    double  temp;

    sphere_to_ray_vector = subtract_vector(ray.origin - create_point(0, 0, 0));
    a = dot_product(ray.direction, ray.direction);
    b = 2 * dot_product(ray.direction, sphere_to_ray_vector);
    c = dot_product(sphere_to_ray_vector, sphere_to_ray_vector) - 1;
    discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return intersections;
    intersections[0] = (-b - sqrt(discriminant)) / (2 * a);
    intersections[1] = (-b + sqrt(discriminant)) / (2 * a);
    if (intersections[0] > intersections[1])
    {
        temp = intersections[0];
        intersections[0] = intersections[1];
        intersections[1] = temp;
    }
    return intersections;
}