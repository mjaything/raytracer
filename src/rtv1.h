/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 04:15:17 by min-kim           #+#    #+#             */
/*   Updated: 2020/04/29 04:15:19 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "mlx.h"
# include "libft.h"

# include <math.h>
# include <string.h>

# define CANVAS_WIDTH 1024
# define CANVAS_HEIGHT 768

typedef struct      s_tuple
{
    double x;
    double y;
    double z;
    double w;
}                   t_tuple;

typedef struct      s_vector
{
    double  x;
    double  y;
    double  z;
}                   t_vector;

typedef struct      s_matrix
{
    int     row;
    int     column;
    double  *value;
}                   t_matrix;

typedef struct      s_env
{
    // t_camera    *camera;
    void            *mlx_ptr;
    void            *win_ptr;
    void            *img_ptr;
    char            *data_addr;
    int             bits_per_pixel;
    int             size_line;
    int             endian;
}                   t_env;

#endif