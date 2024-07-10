/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:33:09 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/21 14:57:21 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_private.h"

static void	setup_hit_record(
				t_hit_record *rec, double t, t_ray *ray, t_obj *obj);

/*
formula: N⋅(P−P0)=0
rec->point = P
rec->norm = N
ray->origin = P0
ray->direction = D
notice:
	1. need to check if the ray is parallel to the plane
		* if the ray is parallel to the plane, then the the denominator will be 0
*/
bool	hit_plane(t_ray *ray, t_obj *plane, t_hit_record *rec)
{
	double	numerator;
	double	denominator;
	double	t_intersection;

	denominator = vec3_dot(plane->norm, ray->direction);
	if (fabs(denominator) < 1e-6)
		return (false);
	numerator = vec3_dot(vec3_sub(plane->position, ray->origin), plane->norm);
	t_intersection = numerator / denominator;
	if (t_intersection <= 0)
		return (false);
	setup_hit_record(rec, t_intersection, ray, plane);
	return (true);
}

static void	setup_hit_record(
				t_hit_record *rec, double t, t_ray *ray, t_obj *obj)
{
	rec->shoot_direction = ray->direction;
	rec->point = vec3_add(ray->origin, vec3_mul(ray->direction, t));
	rec->norm = obj->norm;
	rec->color = obj->color;
	if (vec3_dot(ray->direction, rec->norm) >= 0)
		rec->norm = vec3_mul(rec->norm, -1);
	rec->front_face = true;
	rec->t = t;
}
