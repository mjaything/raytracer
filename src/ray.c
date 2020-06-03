/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:12:52 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/03 15:12:53 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void        configure_light_source(t_env *env, t_light *light)
{
    env->ray.origin = light->origin;
    env->ray.direction = normalize_vector(subtract_vector(env->ray.hit, \
                                                            light->origin));
}