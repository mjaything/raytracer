/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:28:16 by min-kim           #+#    #+#             */
/*   Updated: 2020/06/03 15:28:17 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		ray_sphere_intersection(t_env *env, t_object *object)
{
	t_vector	sphere_to_ray_vector;
	double		discriminant;
	double		a;
	double		b;
	double		c;

	sphere_to_ray_vector = subtract_vector(env->ray.origin, object->origin);
	a = dot_product(env->ray.direction, env->ray.direction);
	b = 2 * dot_product(sphere_to_ray_vector, env->ray.direction);
	c = dot_product(sphere_to_ray_vector, sphere_to_ray_vector) - object->scale;
	discriminant = calculate_discriminant(a, b, c);
	if (discriminant < EPSILON)
		return -1.0;
	else
		return ((-b - sqrt(discriminant)) / (2 * a));
}

double		ray_cone_intersection(t_env *env, t_object *object)
{
	t_vector	cone_to_ray_vector;
	double		discriminant;
	double		a;
	double		b;
	double		c;

	cone_to_ray_vector = subtract_vector(env->ray.origin, object->origin);
	a = env->ray.direction.x * env->ray.direction.x - \
		env->ray.direction.y * env->ray.direction.y + \
		env->ray.direction.z * env->ray.direction.z;
	b = 2 * cone_to_ray_vector.x * env->ray.direction.x - \
		2 * cone_to_ray_vector.y * env->ray.direction.y + \
		2 * cone_to_ray_vector.z * env->ray.direction.z;
	c = cone_to_ray_vector.x * cone_to_ray_vector.x - \
		cone_to_ray_vector.y * cone_to_ray_vector.y + \
		cone_to_ray_vector.z * cone_to_ray_vector.z;
	discriminant = calculate_discriminant(a, b, c);
	if (discriminant < EPSILON)
		return -1.0;
	else
		return ((-b - sqrt(discriminant)) / (2 * a));
}

double		ray_cylinder_intersection(t_env *env, t_object *object)
{
	t_vector	cylinder_to_ray_vector;
	double		discriminant;
	double		a;
	double		b;
	double		c;

	cylinder_to_ray_vector = subtract_vector(env->ray.origin, object->origin);
	a = env->ray.direction.x * env->ray.direction.x + \
		env->ray.direction.z * env->ray.direction.z;
	b = 2 * cylinder_to_ray_vector.x * env->ray.direction.x + \
		2 * cylinder_to_ray_vector.z * env->ray.direction.z;
	c = cylinder_to_ray_vector.x * cylinder_to_ray_vector.x + \
		cylinder_to_ray_vector.z * cylinder_to_ray_vector.z - \
		object->scale;
	discriminant = calculate_discriminant(a, b, c);
	if (discriminant < EPSILON)
		return -1.0;
	else
		return ((-b - sqrt(discriminant)) / (2 * a));
}

double		ray_plane_intersection(t_env *env, t_object *object)
{
	double	intersection;
	double	a;
	double	b;
	double	c;

	a = dot_product(object->direction, env->ray.origin);
	b = dot_product(object->direction, object->origin);
	c = dot_product(object->direction, env->ray.direction);
	intersection = -((a - b)) / c;
	if (intersection < EPSILON)
		return -1.0;
	else
		return intersection;
}

t_object	*ray_object_intersection(t_env *env, \
				double *nonnegative_min_intersection, double *intersection)
{
	t_object	*object;
	t_object	*intersected_object;

	object = env->object;
	while ((object = object->next) != NULL)
	{
		*intersection = env->intersections[object->shape](env, object);
		if (*intersection > EPSILON && \
			*intersection < *nonnegative_min_intersection)
		{
			intersected_object = object;
			*nonnegative_min_intersection = *intersection;
		}
	}
	return intersected_object;
}