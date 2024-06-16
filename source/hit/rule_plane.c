/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:33:09 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/16 15:46:04 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_private.h"

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
bool	hit_plane(t_vec3 vec3, t_ray *ray, t_obj *plane, t_hit_record *rec)
{
	double	numerator;
	double	denominator;
	double	t_intersection;

	denominator = vec3.ops->dot(plane->norm, ray->direction);
	if (fabs(denominator) < 1e-6)
		return (false);
	numerator = vec3.ops->dot(
			vec3.ops->sub(plane->position, ray->origin),
			plane->norm);
	t_intersection = numerator / denominator;
	if (t_intersection < 0)
		return (false);
	setup_hit_record(rec, t_intersection, ray, plane);
	return (true);
}
