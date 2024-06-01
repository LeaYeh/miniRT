/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:21:25 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/01 12:09:36 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "defines.h"
# include "ray.h"
# include "object.h"

typedef struct s_hit_record
{
	t_ray	ray;
	t_vec3	point;
	t_vec3	norm;
	t_vec3	color;
	bool	front_face;
}	t_hit_record;

bool	hit_object(t_ray *ray, t_obj *obj, t_hit_record *rec);

#endif
