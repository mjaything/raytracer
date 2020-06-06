/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:11:49 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/25 14:11:51 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	initialize_camera(t_env *env)
{
	env->camera.position = create_vector(0.0, 0.0, 0.0);
	env->camera.direction = create_vector(0.0, 0.0, 1.0);
	env->camera.rotation_angle = create_vector(0.0, 0.0, 0.0);
	env->camera.field_of_view = 90.0;
	env->camera.anti_aliasing = 4.0;
}

void	parse_camera(t_env *env, int fd)
{
	char	*line;

	initialize_camera(env);
	while (get_next_line(fd, &line) == 1 && ((ft_strstr(line, "}") == NULL)))
	{
		if (ft_strstr(line, "position") != NULL)
			env->camera.position = parse_array(line);
		else if (ft_strstr(line, "rotation") != NULL)
			env->camera.rotation_angle = parse_array(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	env->camera.rotation_angle.x = env->arguments.rotation_angle_x;
	env->camera.rotation_angle.y = env->arguments.rotation_angle_y;
	env->camera.rotation_angle.z = env->arguments.rotation_angle_z;
}

void	configure_camera(t_env *env)
{
	t_vector	vector1;
	t_vector	vector2;
	double		half_field_of_view;

	env->camera.width = WINDOW_WIDTH / WINDOW_HEIGHT;
	env->camera.height = WINDOW_HEIGHT / WINDOW_HEIGHT;
	half_field_of_view = \
					degree_to_radian(env->camera.field_of_view / 2.0);
	env->camera.half_view = tan(half_field_of_view);
	vector1 = multiply_vector_by_scalar(env->camera.direction, \
									1.0 / env->camera.half_view);
	vector2 = create_vector(0.0, env->camera.height / 2.0, 0.0);
	vector1 = add_vector(vector1, vector2);
	vector1 = add_vector(create_vector(0, 0, 0), vector1);
	vector2 = create_vector(env->camera.width / 2.0, 0.0, 0.0);
	env->camera.origin = subtract_vector(vector1, vector2);
	env->camera.xi = env->camera.width / WINDOW_WIDTH;
	env->camera.yi = env->camera.height / WINDOW_HEIGHT;
}