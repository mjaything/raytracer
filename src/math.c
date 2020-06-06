/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:12:14 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/22 20:12:16 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	degree_to_radian(double degrees)
{
	double	radian;

	radian = degrees * (PI / 180);
	return radian;
}

double	calculate_discriminant(double a, double b, double c)
{
	double	discriminant;
    
	discriminant = b * b - 4 * a * c;
	return discriminant;
}