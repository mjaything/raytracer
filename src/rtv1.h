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

# include "../library/libft/libft.h"
# include "../library/minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

# define KEYBOARD_ESC 53
# define EVENT_KEY_PRESS 2
# define EVENT_MASK_KEY_PRESS 1L << 0

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768

# define POSITION_MAXIMUM 1000.0
# define POSITION_MINIMUM -1000.0

# define EPSILON 1e-9
# define PI 3.1415926535

# define ERROR_USAGE    "ERROR: Usage: ./rtv1 scene_file -x [angle] -y [angle] \
                        -z [angle]"
# define ERROR_ENVIRONMENT_INITIALIZATION "ERROR: Check environment initialization"
# define ERROR_SCENE_FILE "ERROR: Check the scene file"
# define ERROR_LIGHT_MEMALLOC "ERROR: Check the memory allocation for parsing lights"
# define ERROR_OBJECT_MEMALLOC "ERROR: Check the memory allocation for parsing objects"
# define ERROR_MLX_INIT "ERROR: Check the process of initiating mlx"
# define ERROR_MLX_NEW_IMAGE "ERROR: Check the process of creating new image"
# define ERROR_MLX_NEW_WINDOW "ERROR: Check the process of creating new window"

enum Shape { SPHERE, CONE, CYLINDER, PLANE };

typedef struct      s_vector
{
    double x;
    double y;
    double z;
}                   t_vector;

typedef struct      s_arguments
{
    char    *scene;
    double  rotation_angle_x;
    double  rotation_angle_y;
    double  rotation_angle_z;
}                   t_arguments;

typedef struct      s_material
{
    t_vector    surface_color;
    double      reflection_ambient;
    double      reflection_diffuse;
    double      reflection_specular;
    double      shininess;
}                   t_material;

typedef struct      s_ray
{
    t_vector    origin;
    t_vector    direction;
    t_vector    hit;
}                   t_ray;

typedef struct      s_light
{
    t_vector    origin;
    t_vector    color;
    double      intensity;
    struct s_light  *next;
}                   t_light;

typedef struct      s_object
{
    t_vector    origin;
    t_vector    direction;
    t_vector    surface_normal;
    t_material  material;
    int         shape;
    double      scale;
    struct s_object *next;
}                   t_object;

typedef struct      s_image
{
    void            *address;
    char            *image_ptr;
    int             bits_per_pixel;
    int             endian;
    int             size_line;
}                   t_image;

typedef struct      s_window
{
    void    *address;
    int     width;
    int     height;
}                   t_window;

typedef struct      s_camera
{
    t_vector    origin;
    t_vector    position;
    t_vector    direction;
    t_vector    rotation_angle;
    double      width;
    double      height;
    double      xi;
    double      yi;
    double      field_of_view;
    double      anti_aliasing;
    double      recursion_threshold;
}                   t_camera;

typedef struct      s_env
{
    t_arguments     arguments;
    t_window        window;
    t_light         *light;
    t_object        *object;
    t_image         img_ptr;
    t_image         image;
    t_camera        camera;
    t_ray           ray;
    t_vector        color;
    t_vector        color_intersection;
    t_vector        color_final;
    void            *mlx_ptr;
    double          i;
    double          j;
    int             trace_recursion_depth;
    double          shadow;
    double          (*intersection[6])(struct s_env *, t_object *);
}                   t_env;

#endif