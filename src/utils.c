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

int     press_keyboard(int keycode)
{
    if (keycode == KEYBOARD_ESC)
        exit(0);
    return 0;
}

void    display_loading(void)
{
    ft_putendl("Loading... This may take up to several minutes.");
}
