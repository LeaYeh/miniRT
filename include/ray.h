/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:37:47 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/31 11:44:31 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec3.h"

typedef struct s_ray
{
	t_vec3	*origin;
	t_vec3	*direction;
	t_vec3	*point_at_parameter;
}	t_ray;

typedef struct s_hit_record
{
	t_ray	ray;
	t_vec3	point;
	t_vec3	norm;
	t_vec3	color;
	bool	front_face;
}	t_hit_record;

#endif
