/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 04:32:36 by min-kim           #+#    #+#             */
/*   Updated: 2020/04/29 04:32:38 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	create_vector(double x, double y, double z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_vector	add_vector(t_vector vector1, t_vector vector2)
{
	t_vector	added_vector;

	added_vector.x = vector1.x + vector2.x;
	added_vector.y = vector1.y + vector2.y;
	added_vector.z = vector1.z + vector2.z;
	return (added_vector);
}

t_vector	subtract_vector(t_vector vector1, t_vector vector2)
{
	t_vector 	subtracted_vector;

	subtracted_vector.x = vector1.x - vector2.x;
	subtracted_vector.y = vector1.y - vector2.y;
	subtracted_vector.z = vector1.z - vector2.z;
	return (subtracted_vector);
}

t_vector	multiply_vector_by_scalar(t_vector vector, double c)
{
	t_vector	multiplied_vector;

	multiplied_vector.x = c * vector.x;
	multiplied_vector.y = c * vector.y;
	multiplied_vector.z = c * vector.z;
	return (multiplied_vector);
}
