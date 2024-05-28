/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:41:00 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/28 15:10:09 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <stdio.h>
# include <stdbool.h>
# include "vec3.h"

/* Error Codes */
# define SUCCESS			0
# define ERR_ARGC			1

typedef struct s_amblight
{
	t_vec3	*color;
	double	ratio;
}	t_amblight;

typedef struct s_camera
{
	t_vec3	*position;
	t_vec3	*norm;
	double	fov;
}	t_camera;

typedef struct s_light
{
	t_vec3	*position;
	t_vec3	*color;
	double	ratio;
}	t_light;

typedef enum e_object_type
{
	SPHERE		= 0,
	PLANE,
	CYLINDER
}	t_obj_type;

typedef struct s_object
{
	t_obj_type  type;
	t_vec3		*position;
	t_vec3		*color;
	t_vec3		*norm;
	double		d_param1;
	double		d_param2;
}	t_obj;

typedef struct s_scene
{
	t_light		*light;
	t_amblight	*amblight;
	t_camera	*camera;
	t_obj		**objects;
}	t_scene;

#endif
