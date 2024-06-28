/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:21:25 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/25 18:15:59 by ldulling         ###   ########.fr       */
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

bool	shoot_ray(void *param, t_ray *ray);
bool	hit_object(t_ray *ray, t_obj *obj, t_hit_record *rec);
double	min_positive_t(double t1, double t2);
bool	is_min_positive_t(double this, double other);

#endif
