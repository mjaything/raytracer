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

int main(int argc, char **argv)
{
    if (argc == 8)
    {
        t_env env;

        parse_arguments(&env, argc, argv);
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