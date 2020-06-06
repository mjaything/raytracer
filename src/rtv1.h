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
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>

# define KEYBOARD_ESC 53
# define EVENT_KEY_PRESS 2
# define EVENT_MASK_KEY_PRESS 1L << 0

# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500

# define POSITION_MAXIMUM 1000.0
# define POSITION_MINIMUM -1000.0

# define EPSILON 1e-9
# define PI 3.1415926

# define ERROR_USAGE    "ERROR: Usage: ./rtv1 scene_file -x [angle] \
                        -y [angle] -z [angle]"
# define ERROR_ENVIRONMENT_INITIALIZATION "ERROR: Check environment \
                                            initialization"
# define ERROR_SCENE_FILE "ERROR: Check the scene file"
# define ERROR_LIGHT_MEMALLOC "ERROR: Check the memory allocation for parsing \
                                lights"
# define ERROR_OBJECT_MEMALLOC "ERROR: Check the memory allocation for parsing \
                                objects"
# define ERROR_MLX_INIT "ERROR: Check the process of initiating mlx"
# define ERROR_MLX_NEW_IMAGE "ERROR: Check the process of creating new image"
# define ERROR_MLX_NEW_WINDOW "ERROR: Check the process of creating new window"

enum Shape { SPHERE, CONE, CYLINDER, PLANE };

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct		s_arguments
{
	char			*scene;
	double 			rotation_angle_x;
	double			rotation_angle_y;
	double			rotation_angle_z;
}					t_arguments;

typedef struct		s_material
{
	t_vector		surface_color;
	double			reflection_ambient;
	double			reflection_diffuse;
	double			reflection_specular;
	double			shininess;
}					t_material;

typedef struct		s_ray
{
	t_vector		origin;
	t_vector		direction;
	t_vector		hit;
	int				x;
	int				y;
}					t_ray;

typedef struct		s_light
{
	t_vector		origin;
	t_vector		color;
	double			intensity;
	double			attenuation;
	double			quadratic;
	double			constant;
	double			linear;
	struct s_light  *next;
}					t_light;

typedef struct		s_object
{
	t_vector		origin;
	t_vector		direction;
	t_vector		surface_normal;
	t_material		material;
	short			shape;
	double			scale;
	struct s_object *next;
}					t_object;

typedef struct		s_image
{
	void			*address;
	char			*image_ptr;
	int				bits_per_pixel;
	int				endian;
	int				size_line;
}					t_image;

typedef struct		s_window
{
	void    		*address;
	int				width;
    int				height;
    int				dwidth;
	int				dheight;
}					t_window;

typedef struct		s_camera
{
	t_vector		origin;
	t_vector		position;
	t_vector		direction;
	t_vector		rotation_angle;
	double			width;
	double			height;
	double			xi;
	double			yi;
	double			field_of_view;
	double			half_view;
	double			anti_aliasing;
}					t_camera;

typedef struct		s_env
{
	t_arguments		arguments;
	t_window		window;
	t_light			*light;
	t_object		*object;
	t_image			image;
	t_camera		camera;
	t_ray			ray;
	t_vector		color;
	t_vector		color_intersection;
	t_vector		color_final;
	double			(*intersections[6])(struct s_env *, t_object *);
	void			*mlx_ptr;
	double			shadow;
	double			i;
	double			j;
}					t_env;

void		initialize_camera(t_env *env);
void		configure_camera(t_env *env);
t_vector	decompose_color(int color_hex);
double		ray_cone_intersection(t_env *env, t_object *object);
double		ray_cylinder_intersection(t_env *env, t_object *object);
void		image_pixel_put(t_env *env, int x, int y, t_vector color_rgb);
int			handle_expose_event(t_env *env);
int			handle_no_event(t_env *env);
void		handle_events(t_env *env);
void		find_surface_normal(t_env *env, t_object *object);
void		find_shadows(t_env *env, t_object *object, \
				double *nonnegative_min_intersection, double *intersection);
void		initialize_environment(t_env *env);
void		initialize_light(t_light *light);
void		initialize_object(t_object *object);
void		initialize_material(t_material *material);
void		initialize_image(t_env *env);
void		initialize_trace(t_env *env);
double		degree_to_radian(double degrees);
double		calculate_discriminant(double a, double b, double c);
void		parse_arguments(t_env *env, char **argv);
t_vector	parse_array(char *line);
void		parse_camera(t_env *env, int fd);
t_vector	parse_color(char *line);
double		parse_float(char *line);
t_light		*parse_light(int fd);
int			parse_shape(char *line);
t_material	parse_material(int fd);
t_object	*parse_object(int fd);
void		parse_scene(t_env *env);
double		ray_plane_intersection(t_env *env, t_object *object);
void		configure_light_source(t_env *env, t_light *light);
t_object	*ray_object_intersection(t_env *env, \
				double *nonnegative_min_intersection, double *intersection);
t_vector	reflect_vector_at_surface_normal(t_vector input_vector, \
											t_vector surface_normal);
t_vector	calculate_diffuse_contribution(t_env *env, t_object *object, \
											t_light *light);
t_vector	calculate_specular_contribution(t_env *env, t_object *object, \
											t_light *light);
void		trace_color(t_env *env, t_object *object, \
					double *nonnegative_min_intersection, double *intersection);
void		trace_reflection(t_env *env, t_object *object);
void		trace_draw(t_env *env);
void		trace(t_env *env);
void		render_scene(t_env *env);
void		rotation_x_axis(t_vector *vector, double degree);
void		rotation_y_axis(t_vector *vector, double degree);
void		rotation_z_axis(t_vector *vector, double degree);
void		rotate_vector(t_vector *vector, t_vector rotation_angle);
double		ray_sphere_intersection(t_env *env, t_object *object);
void		terminate(char *str);
int			press_keyboard(int keycode);
void		display_loading(void);
t_vector	create_vector(double x, double y, double z);
t_vector	add_vector(t_vector vector1, t_vector vector2);
t_vector	subtract_vector(t_vector vector1, t_vector vector2);
t_vector	multiply_vector_by_scalar(t_vector vector, double c);
double		calculate_magnitude(t_vector vector);
t_vector	normalize_vector(t_vector vector);
double		dot_product(t_vector vector1, t_vector vector2);
t_vector	cross_product(t_vector vector1, t_vector vector2);
t_vector	hadamard_product(t_vector vector1, t_vector vector2);
void		clamp_vector(t_vector *vector, double min, double max);

#endif
