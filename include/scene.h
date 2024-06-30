/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:22:43 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/30 20:10:31 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "vec3.h"
# include "camera.h"
# include "libft.h"

typedef struct s_amblight
{
	bool	is_init;
	t_vec3	color;
	double	org_brightness;
	double	brightness;
}	t_amblight;

typedef struct s_light
{
	bool	is_init;
	t_vec3	org_position;
	t_vec3	position;
	t_vec3	translation;
	t_vec3	color;
	double	org_brightness;
	double	brightness;
}	t_light;

typedef struct s_scene
{
	t_vec3		bg_color;
	t_amblight	amblight;
	t_camera	camera;
	t_light		light;
	t_list_d	*objects;
}	t_scene;

#endif
