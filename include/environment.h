/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:22:43 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/26 18:16:18 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "libft.h"
# include "vec3.h"
# include "camera.h"

typedef struct s_amblight
{
	t_vec3	color;
	double	ratio;
}	t_amblight;

typedef struct s_light
{
	t_vec3	org_position;
	t_vec3	position;
	t_vec3	translation;
	t_vec3	color;
	double	ratio;
}	t_light;

typedef struct s_scene
{
	t_vec3		bg_color;
	t_amblight	amblight;
	t_camera	camera;
	t_light		light;
	t_list		*objects;
}	t_scene;

#endif
