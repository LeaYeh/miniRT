/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:41:00 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/30 01:14:45 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <stdio.h>
# include <stdbool.h>
# include "vec3.h"
# include "libft.h"

/* Error Codes */
# define SUCCESS			0
# define ERR_ARGC			1

# define SPHERE_ARG_NUM		3
# define PLANE_ARG_NUM		3
# define CYLINDER_ARG_NUM	5

# define INVALID_FILE			"invalid file format.\n"
# define INVALID_CONTENT_FMT	"invalid content format.\n"
# define FAILED_OPEN_FILE		"failed to open file.\n"
# define FAILED_ALLOC_MEM		"failed to allocate memory.\n"
# define INVALID_NUM_ARG		"invalid number of argument.\n"
# define INVALID_NUM_FMT		"invalid number format.\n"
# define FAILED_PARSE_VEC		"parse vector failed.\n"

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
	t_obj_type	type;
	t_vec3		*position;
	t_vec3		*color;
	t_vec3		*norm;
	double		d_param1;
	double		d_param2;
}	t_obj;

typedef struct s_scene
{
	t_amblight	*amblight;
	t_camera	*camera;
	t_light		*light;
	t_list		*objects;
}	t_scene;

#endif
