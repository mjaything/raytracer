/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:26:30 by min-kim           #+#    #+#             */
/*   Updated: 2020/06/05 05:26:32 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		initialize_material(t_material *material)
{
	material->surface_color = create_vector(0.1, 0.1, 0.1);
	material->reflection_ambient = 0.0;
	material->reflection_diffuse = 0.0;
	material->reflection_specular = 0.0;
	material->shininess = 0.0;
}

t_material	parse_material(int fd)
{
	t_material	material;
	char		*line;

	initialize_material(&material);
	while ((get_next_line(fd, &line) == 1) && (ft_strstr(line, "}") == NULL))
	{
		if (ft_strstr(line, "color") != NULL)
			material.surface_color = parse_color(line);
		else if (ft_strstr(line, "reflection_ambient") != NULL)
			material.reflection_ambient = parse_float(line);
		else if (ft_strstr(line, "reflection_diffuse") != NULL)
			material.reflection_diffuse = parse_float(line);
		else if (ft_strstr(line, "reflection_specular") != NULL)
			material.reflection_specular = parse_float(line);
		else if (ft_strstr(line, "shininess") != NULL)
			material.shininess = parse_float(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return material;
}