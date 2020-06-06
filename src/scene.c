/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:22:32 by min-kim           #+#    #+#             */
/*   Updated: 2020/06/05 05:22:34 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	render_scene(t_env *env)
{
	if (!(env->mlx_ptr = mlx_init()))
		terminate(ERROR_MLX_INIT);
	if (!(env->window.address = \
		mlx_new_window(env->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, \
						env->arguments.scene)))
		terminate(ERROR_MLX_INIT);
	initialize_image(env);
	display_loading();
	trace(env);
}

void	parse_scene(t_env *env)
{
	t_light		*light;
	t_object	*object;
	char		*line;
	int			fd;

	if (!((fd = open(env->arguments.scene, O_RDWR)) > 0))
		terminate(ERROR_SCENE_FILE);
	light = env->light;
	object = env->object;
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strstr(line, "Camera") != NULL)
			parse_camera(env, fd);
		else if ((ft_strstr(line, "Lights") != NULL) && \
				(light->next = parse_light(fd)))
			light = light->next;
		else if ((ft_strstr(line, "Objects") != NULL) && \
				(object->next = parse_object(fd)))
			object = object->next;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (close(fd) == -1)
		terminate(ERROR_SCENE_FILE);
}