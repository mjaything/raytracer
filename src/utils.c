/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 02:57:35 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/08 02:57:37 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    terminate(char *str)
{
    ft_putendl_fd(str, 2);
    exit(1);
}

void    display_loading(void)
{
    ft_putendl("Loading... This may take up to several minutes.");
}

void        clamp_vector(t_vector *vector, double min, double max)
{
    if (vector->x < min)
        vector->x = min;
    if (vector->x > max)
        vector->x = max;
    if (vector->y < min)
        vector->y = min;
    if (vector->y > max)
        vector->y = max;
    if (vector->z < min)
        vector->z = min;
    if (vector->z > max)
        vector->z = max;
}