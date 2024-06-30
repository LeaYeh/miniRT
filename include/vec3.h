/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:19:11 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/24 17:24:17 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include "defines.h"

typedef struct s_vector_3d
{
	double				x;
	double				y;
	double				z;
}	t_vec3;

t_vec3		vector(double x, double y, double z);
t_vec3		unit_vector(double x, double y, double z);
t_vec3		vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3		vec3_sub(t_vec3 v1, t_vec3 v2);
t_vec3		vec3_mul(t_vec3 v, double scalar);
t_vec3		vec3_div(t_vec3 v, double scalar);
double		vec3_dot(t_vec3 v1, t_vec3 v2);
t_vec3		vec3_cross(t_vec3 v1, t_vec3 v2);
t_vec3		vec3_mul_components(t_vec3 v1, t_vec3 v2);
double		vec3_magnitude(t_vec3 v);
t_vec3		vec3_normalize(t_vec3 v);

#endif
