/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:44:06 by min-kim           #+#    #+#             */
/*   Updated: 2020/06/05 05:44:07 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		calculate_magnitude(t_vector vector)
{
	double magnitude;

	magnitude = sqrt(vector.x * vector.x + vector.y * vector.y + \
					vector.z * vector.z);
	return (magnitude);
}

t_vector	normalize_vector(t_vector vector)
{
	t_vector	normalized_vector;
	double		magnitude;

	magnitude = calculate_magnitude(vector);
	normalized_vector.x = vector.x / magnitude;
	normalized_vector.y = vector.y / magnitude;
	normalized_vector.z = vector.z / magnitude;
	return (normalized_vector);
}
