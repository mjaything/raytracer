/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 01:45:54 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/27 01:45:55 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		handle_expose_event(t_env *env)
{
	mlx_put_image_to_window(env->mlx_ptr, env->window.address, \
							env->image.address, 0, 0);
	return (0);
}

int		handle_no_event(t_env *env)
{
	handle_expose_event(env);
	return (0);
}

int		press_keyboard(int keycode)
{
	if (keycode == KEYBOARD_ESC)
		exit(0);
	return (0);
}

void	handle_events(t_env *env)
{
	mlx_hook(env->window.address, EVENT_KEY_PRESS, 1L << 0, \
			press_keyboard, env);
	mlx_expose_hook(env->window.address, handle_expose_event, env);
	mlx_loop_hook(env->mlx_ptr, handle_no_event, env);
	mlx_loop(env->mlx_ptr);
}
