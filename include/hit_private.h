/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:31:21 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/24 21:39:32 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_PRIVATE_H
# define HIT_PRIVATE_H

# include "hit.h"
# include "ray.h"

bool	hit_object(t_ray *ray, t_obj *obj, t_hit_record *rec);
bool	hit_sphere(t_vec3 vec3, t_ray *ray, t_obj *sphere, t_hit_record *rec);
bool	hit_plane(t_vec3 vec3, t_ray *ray, t_obj *plane, t_hit_record *rec);
bool	hit_cylinder(t_vec3 vec3,
			t_ray *ray, t_obj *cylinder, t_hit_record *rec);
double	calc_sphere_min_root(double a, double b, double c);
bool	is_point_in_cap_range(t_vec3 p,
			t_obj *cylinder, t_vec3 center_top, t_vec3 center_bottom);
bool	is_point_in_height_range(t_vec3 p, t_obj *cylinder);

#endif
