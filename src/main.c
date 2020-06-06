/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 02:55:27 by min-kim           #+#    #+#             */
/*   Updated: 2020/04/29 02:55:34 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_arguments(t_env *env, char **argv)
{   
	env->arguments.scene = ft_strdup(argv[1]);
	if (!(ft_strcmp(argv[2], "-x")) && !(ft_strcmp(argv[4], "-y")) && \
		!(ft_strcmp(argv[6], "-z")))
	{
		env->arguments.rotation_angle_x = ft_atof(argv[3]);
		env->arguments.rotation_angle_y = ft_atof(argv[5]);
		env->arguments.rotation_angle_z = ft_atof(argv[7]);
	}
	else
		terminate(ERROR_USAGE);
}

void	initialize_environment(t_env *env)
{
	t_light		*light;
	t_object	*object;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		terminate(ERROR_ENVIRONMENT_INITIALIZATION);
	if (!(object = (t_object *)malloc(sizeof(t_object))))
		terminate(ERROR_ENVIRONMENT_INITIALIZATION);
	env->light = light;
	env->light->next = NULL;
	env->object = object;
	env->object->next = NULL;
	env->window.width = WINDOW_WIDTH;
	env->window.height = WINDOW_HEIGHT;
	env->window.dwidth = WINDOW_WIDTH / 2;
	env->window.dheight = WINDOW_HEIGHT / 2;
	env->intersections[0] = ray_sphere_intersection;
	env->intersections[1] = ray_cone_intersection;
	env->intersections[2] = ray_cylinder_intersection;
	env->intersections[3] = ray_plane_intersection;
	env->shadow = 1.0;
}

int		main(int argc, char **argv)
{
	if (argc == 8)
	{
		t_env env;

		parse_arguments(&env, argv);
		initialize_environment(&env);
		parse_scene(&env);
		configure_camera(&env);
		render_scene(&env);
		handle_events(&env);
	}
	else
		terminate(ERROR_USAGE);
	return 0;
}