/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:23:43 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/01 11:31:48 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vec3.h"

typedef enum e_object_type
{
	SPHERE		= 0,
	PLANE,
	CYLINDER
}	t_obj_type;

typedef struct s_object
{
	t_obj_type	type;
	t_vec3		position;
	t_vec3		color;
	t_vec3		norm;
	double		d_param1;
	double		d_param2;
}	t_obj;

#endif
