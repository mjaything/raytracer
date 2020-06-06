/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:12:52 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/03 15:12:53 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		initialize_light(t_light *light)
{
	light->origin = create_vector(0.0, 0.0, 0.0);
	light->color = create_vector(0.0, 0.0, 0.0);
	light->intensity = 1.0;
	light->quadratic = 0.000007;
	light->linear = 0.0014;
	light->constant = 1.0;
}

t_light		*parse_light(int fd)
{
	t_light	*light;
	char	*line;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		terminate(ERROR_LIGHT_MEMALLOC);
	initialize_light(light);
	while (get_next_line(fd, &line) == 1 && (ft_strstr(line, "}") == NULL))
	{
		if (ft_strstr(line, "origin") != NULL)
			light->origin = parse_array(line);
		else if (ft_strstr(line, "color") != NULL)
			light->color = parse_color(line);
		else if (ft_strstr(line, "intensity") != NULL)
			light->intensity = parse_float(line);
		else if (ft_strstr(line, "linear") != NULL)
			light->linear = parse_float(line);
		else if (ft_strstr(line, "quadratic") != NULL)
			light->quadratic = parse_float(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	light->next = NULL;
	return (light);
}

void		configure_light_source(t_env *env, t_light *light)
{
	env->ray.origin = light->origin;
	env->ray.direction = normalize_vector(subtract_vector(env->ray.hit, \
															light->origin));
}
