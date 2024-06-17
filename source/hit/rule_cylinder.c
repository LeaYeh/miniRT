/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:35:18 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/17 12:01:54 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_private.h"

static bool	hit_cylinder_side(t_vec3 vec3,
				t_ray *ray, t_obj *cylinder, t_hit_record *rec);
static bool	hit_cylinder_caps(t_vec3 vec3,
				t_ray *ray, t_obj *cylinder, t_hit_record *rec);
static bool	is_point_in_height_range(t_vec3 vec3, t_vec3 p, t_obj *cylinder);

/*
formula: (P−P0−(P−P0)⋅D⋅D)⋅(P−P0−(P−P0)⋅D⋅D)−r^2=0
rec->point = P
rec->norm = N
ray->origin = P0
ray->direction = D
*/

bool	hit_cylinder(t_vec3 vec3,
			t_ray *ray, t_obj *cylinder, t_hit_record *rec)
{
	t_hit_record	rec_side;
	t_hit_record	rec_caps;

	if (!hit_cylinder_side(vec3, ray, cylinder, &rec_side))
		return (false);
	if (!hit_cylinder_caps(vec3, ray, cylinder, &rec_caps))
		return (false);
	if (rec_side.t < rec_caps.t)
		*rec = rec_side;
	else
		*rec = rec_caps;
	return (true);
}

bool	hit_cylinder_side(t_vec3 vec3,
			t_ray *ray, t_obj *cylinder, t_hit_record *rec)
{
	const t_vec3	oc = vec3.ops->sub(ray->origin, cylinder->position);
	double			a;
	double			b;
	double			c;
	double			t_intersection;

	a = vec3.ops->dot(ray->direction, ray->direction) - \
			pow(vec3.ops->dot(ray->direction, cylinder->norm), 2);
	b = 2 * (vec3.ops->dot(ray->direction, oc) - \
			vec3.ops->dot(ray->direction, cylinder->norm) * \
			vec3.ops->dot(oc, cylinder->norm));
	c = vec3.ops->dot(oc, oc) - \
			pow(vec3.ops->dot(oc, cylinder->norm), 2) - \
			pow(cylinder->d_param1, 2);
	t_intersection = calc_sphere_min_root(a, b, c);
	if (t_intersection < 0)
		return (false);
	if (!is_point_in_height_range(vec3,
			vec3.ops->add(
				ray->origin, vec3.ops->mul(ray->direction, t_intersection)),
			cylinder))
		return (false);
	setup_hit_record(rec, t_intersection, ray, cylinder);
	return (true);
}

bool	is_point_in_height_range(t_vec3 vec3, t_vec3 p, t_obj *cylinder)
{
	double	pc_proj;
	double	cy_proj_min;
	double	cy_proj_max;

	pc_proj = vec3.ops->dot(p, cylinder->norm);
	cy_proj_min = vec3.ops->dot(
			cylinder->position, cylinder->norm) - cylinder->d_param2 / 2;
	cy_proj_max = vec3.ops->dot(
			cylinder->position, cylinder->norm) + cylinder->d_param2 / 2;
	if (pc_proj < cy_proj_min || \
		pc_proj > cy_proj_max)
		return (false);
	return (true);
}

bool	hit_cylinder_caps(t_vec3 vec3,
			t_ray *ray, t_obj *cylinder, t_hit_record *rec)
{
	double	t_intersection;
	double	t1;
	double	t2;

	t1 = (cylinder->d_param2 / 2 - vec3.ops->dot(
				ray->origin, cylinder->norm)) / vec3.ops->dot(
			ray->direction, cylinder->norm);
	t2 = (-cylinder->d_param2 / 2 - vec3.ops->dot(
				ray->origin, cylinder->norm)) / vec3.ops->dot(
			ray->direction, cylinder->norm);
	if (t1 < 0 && t2 < 0)
		return (false);
	if (t1 < 0)
		t_intersection = t2;
	else if (t2 < 0)
		t_intersection = t1;
	else if (t1 < t2)
		t_intersection = t1;
	else
		t_intersection = t2;
	setup_hit_record(rec, t_intersection, ray, cylinder);
	return (true);
}
