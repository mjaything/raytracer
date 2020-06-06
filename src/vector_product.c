/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:42:12 by min-kim           #+#    #+#             */
/*   Updated: 2020/06/05 05:42:14 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double      dot_product(t_vector vector1, t_vector vector2)
{
    double number;

    number = vector1.x * vector2.x + vector1.y * vector2.y + \
            vector1.z * vector2.z; 
    return number;
}

t_vector    hadamard_product(t_vector vector1, t_vector vector2)
{
    t_vector resultant_vector;

    resultant_vector.x = vector1.x * vector2.x;
    resultant_vector.y = vector1.y * vector2.y;
    resultant_vector.z = vector1.z * vector2.z;
    return resultant_vector;
}