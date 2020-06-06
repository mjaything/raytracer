/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 19:59:17 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/22 19:59:18 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		rotation_x_axis(t_vector *vector, double degree)
{
	t_vector	rotated_vector;
	double		radian;

	radian = degree_to_radian(degree);
	rotated_vector.x = vector->x;
	rotated_vector.y = vector->y * cos(radian) - vector->z * sin(radian);
	rotated_vector.z = vector->y * sin(radian) + vector->z * cos(radian);
	*vector = rotated_vector;
}

void		rotation_y_axis(t_vector *vector, double degree)
{
	t_vector	rotated_vector;
	double		radian;

	radian = degree_to_radian(degree);
	rotated_vector.x = vector->x * cos(radian) - vector->z * sin(radian);
	rotated_vector.y = vector->y;
	rotated_vector.z = vector->x * sin(radian) + vector->z * cos(radian);
	*vector = rotated_vector;
}

void		rotation_z_axis(t_vector *vector, double degree)
{
	t_vector	rotated_vector;
	double		radian;

	radian = degree_to_radian(degree);
	rotated_vector.x = vector->x * cos(radian) - vector->y * sin(radian);
	rotated_vector.y = vector->x * sin(radian) + vector->y * cos(radian);
	rotated_vector.z = vector->z;
	*vector = rotated_vector;
}

void		rotate_vector(t_vector *vector, t_vector rotation_angle)
{
	rotation_x_axis(vector, rotation_angle.x);
	rotation_y_axis(vector, rotation_angle.y);
	rotation_z_axis(vector, rotation_angle.z);
}