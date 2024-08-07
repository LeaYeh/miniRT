/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:23:43 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/29 21:16:25 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vec3.h"

typedef enum e_object_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_obj_type;

typedef struct s_object
{
	t_obj_type	type;
	t_vec3		org_position;
	t_vec3		org_norm;
	t_vec3		position;
	t_vec3		norm;
	t_vec3		color;
	double		org_diameter;
	double		org_height;
	double		diameter;
	double		height;
	t_vec3		translation;
	t_vec3		rotation;
}	t_obj;

t_obj	init_plane(t_vec3 position, t_vec3 norm, t_vec3 color);

#endif
