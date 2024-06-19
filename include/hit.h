/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:21:25 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/19 17:08:59 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "defines.h"
# include "ray.h"
# include "object.h"
# include "environment.h"

typedef struct s_hit_record
{
	t_vec3	shoot_direction;
	t_vec3	point;
	t_vec3	norm;
	t_vec3	color;
	bool	front_face;
	double	t;
}	t_hit_record;

bool	shoot_ray(t_list *object_list, t_ray *ray);

#endif
