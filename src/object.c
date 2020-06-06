/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 02:33:35 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/02 02:33:37 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	parse_array(char *line)
{
	t_vector	vector;
	char		**array_split;
	int			i;
	int			j;

	vector = create_vector(0.0 , 0.0, 0.0);
	array_split = ft_strsplit(line, ' ');
	i = 0;
	j = 0;
	while (array_split[i] != NULL && j < 3)
	{
		if (ft_hasdigit(array_split[i]))
			j++;
		if (j == 1)
			vector.x = ft_atof(array_split[i]);
		else if (j == 2)
			vector.y = ft_atof(array_split[i]);
		else if (j == 3)
			vector.z = ft_atof(array_split[i]);
		ft_strdel(&array_split[i]);
		i++;
	}
	ft_strdel(&array_split[i]);
	free(array_split);
	clamp_vector(&vector, POSITION_MINIMUM, POSITION_MAXIMUM);
	return (vector);
}

double		parse_float(char *line)
{
	char	*finder;
	double	number;

	finder = ft_strstr(line, ":") + 1;
	number = ft_atof(finder);
	return (number);
}

int			parse_shape(char *line)
{
	int		shape;

	shape = SPHERE;
	if (ft_strstr(line, "sphere") != NULL)
		shape = SPHERE;
	else if (ft_strstr(line, "cone") != NULL)
		shape = CONE;
	else if (ft_strstr(line, "cylinder") != NULL)
		shape = CYLINDER;
	else if (ft_strstr(line, "plane") != NULL)
		shape = PLANE;
	return (shape);
}

void		initialize_object(t_object *object)
{
	object->shape = SPHERE;
	object->origin = create_vector(0.0, 0.0, 0.0);
	object->direction = create_vector(0.0, 0.0, 0.0);
	object->scale = 1.0;
}

t_object	*parse_object(int fd)
{
	t_object	*object;
	char		*line;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		terminate(ERROR_OBJECT_MEMALLOC);
	initialize_object(object);
	while ((get_next_line(fd, &line) == 1) && (ft_strstr(line, "}") == NULL))
	{
		if (ft_strstr(line, "shape") != NULL)
			object->shape = parse_shape(line);
		else if (ft_strstr(line, "origin") != NULL)
			object->origin = parse_array(line);
		else if (ft_strstr(line, "direction") != NULL)
			object->direction = parse_array(line);
		else if (ft_strstr(line, "material") != NULL)
			object->material = parse_material(fd);
		else if (ft_strstr(line, "scale") != NULL)
			object->scale = parse_float(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	object->next = NULL;
	return (object);
}
