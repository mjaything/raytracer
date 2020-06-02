/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 02:33:35 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/02 02:33:37 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    parse_arguments(t_env *env, int argc, char **argv)
{   
    env->arguments.scene = ft_strdup(argv[1]);
    if (ft_strcmp(argv[3], "-x") == 0 && ft_strcmp(argv[5], "-y") == 0 && \
        ft_strcmp(argv[7], "-z") == 0)
    {
        env->arguments.rotation_angle_x = ft_atof(argv[4]);
        env->arguments.rotation_angle_y = ft_atof(argv[6]);
        env->arguments.rotation_angle_z = ft_atof(argv[8]);
    }
    else
        terminate(ERROR_USAGE);
}

t_vector    parse_array(char *line)
{
    t_vector    vector;
    char        **array_split;
    int         i;
    int         j;

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
    return vector;
}

void    parse_camera(t_env *env, int fd)
{
    char    *line;

    initialize_camera(env);
    while (get_next_line(fd, &line) == 1 && (ft_strstr(line, "}") == NULL))
    {
        if (ft_strstr(line, "origin") != NULL)
            env->camera.origin = parse_array(line);
        else if (ft_strstr(line, "rotation") != NULL)
            env->camera.rotation_angle = parse_array(line);
        ft_strdel(&line);
    }
    ft_strdel(&line);
    if (env->arguments.rotation_angle_x < INFINITY)
        env->camera.rotation_angle.x = env->arguments.rotation_angle_x;
    if (env->arguments.rotation_angle_y < INFINITY)
        env->camera.rotation_angle.y = env->arguments.rotation_angle_y;
    if (env->arguments.rotation_angle_z < INFINITY)
        env->camera.rotation_angle.z = env->arguments.rotation_angle_z;
}

t_vector    parse_color(char *line)
{
    int         color_hex;
    t_vector    color_rgb;

    color_hex = ft_atoi_base(line, 16);
    color_rgb = decompose_color(color_hex);
    return color_rgb;
}

double      parse_float(char *line)
{
    char    *finder;
    double  number;

    finder = ft_strstr(line, ":");
    finder += 2;
    number = ft_atof(finder);
    return number;
}

t_light *parse_light(int fd)
{
    t_light *light;
    char    *line;

    if (!(light = (t_light *)ft_memalloc(sizeof(t_light))))
        terminate(ERROR_LIGHT_MEMALLOC);
    initialize_light(light);
    while (get_next_line(fd, &line) == 1 && (ft_strstr(line, "}") == NULL))
    {
        if (ft_strstr(line, "origin") != NULL)
            light->origin = parse_array(line);
        else if (ft_strstr(line, "color") != NULL)
            light->color = parse_color(line);
        else if (ft_strstr(line, "intensity") != NULL)
            light->intensity = parse_float(line);
        ft_strdel(&line);
    }
    ft_strdel(&line);
    light->next = NULL;
    return light;
}

int         parse_shape(char *line)
{
    int shape;

    if (ft_strstr(line, "sphere") != NULL)
        shape = SPHERE;
    else if (ft_strstr(line, "cone") != NULL)
        shape = CONE;
    else if (ft_strstr(line, "cylinder") != NULL)
        shape = CYLINDER;
    else if (ft_strstr(line, "plane") != NULL)
        shape = PLANE;
    return shape;
}

t_material  parse_material(int fd)
{
    t_material material;
    char        *line;

    initialize_material(&material);
    while ((get_next_line(fd, &line) == 1) && (ft_strstr(line, "}") == NULL))
    {
        if (ft_strstr(line, "surface_color") != NULL)
            material.color = parse_color(line);
        else if (ft_strstr(line, "reflection_ambient") != NULL)
            material.reflection_ambient = parse_float(line);
        else if (ft_strstr(line, "reflection_diffuse") != NULL)
            material.reflection_diffuse = parse_float(line);
        else if (ft_strstr(line, "reflection_specular") != NULL)
            material.reflection_specular = parse_float(line);
        else if (ft_strstr(line, "shininess") != NULL)
            material.shininess = parse_float(line);
        ft_strdel(&line);
    }
    ft_strdel(&line);
    return material;
}

t_object    *parse_object(int fd)
{
    t_object    *object;
    char        *line;

    if (!(object = (t_object *)ft_memalloc(sizeof(t_object))))
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
    return object;
}

void    parse_scene(t_env *env)
{
    t_light     *light;
    t_object    *object;
    char        *line;
    int         fd;
    
    if (!((fd = open(env->arguments.scene, O_RDWR)) > 0))
        terminate(ERROR_SCENE_FILE);
    light = env->light;
    object = env->object;
    while (get_next_line(fd, &line) == 1)
    {
        if (ft_strstr(line, "Camera") != NULL)
            parse_camera(env, fd);
        else if ((ft_strstr(line, "Lights") != NULL) && \
                    light->next = parse_light(fd))
            light = light->next;
        else if ((ft_strstr(line, "Objects") != NULL) && \
                    object->next = parse_object(fd))
            object = object->next;
        ft_strdel(&line);
    }
    ft_strdel(&line);
    if (close(fd) == -1)
        terminate(ERROR_SCENE_FILE);
}