/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:35:18 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/20 16:55:15 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_private.h"
#include "debug.h"

static bool	hit_cylinder_side(t_vec3 vec3,
				t_ray *ray, t_obj *cylinder, t_hit_record *rec);
static bool	hit_cylinder_caps(t_vec3 vec3,
				t_ray *ray, t_obj *cylinder, t_hit_record *rec);
static bool	is_point_in_height_range(t_vec3 vec3, t_vec3 p, t_obj *cylinder);
static void	setup_hit_record_side(
				t_hit_record *rec, double t, t_ray *ray, t_obj *cylinder);
static void	setup_hit_record_caps(
				t_hit_record *rec, double t, t_ray *ray, t_obj *cylinder);

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
	bool			hit_side;
	bool			hit_caps;
	t_hit_record	rec_side;
	t_hit_record	rec_caps;

	hit_side = hit_cylinder_side(vec3, ray, cylinder, &rec_side);
	hit_caps = hit_cylinder_caps(vec3, ray, cylinder, &rec_caps);
	if (!hit_side && !hit_caps)
		return (false);
	else if (hit_side && !hit_caps)
		*rec = rec_side;
	else if (!hit_side && hit_caps)
		*rec = rec_caps;
	else if (rec_side.t < rec_caps.t)
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
	setup_hit_record_side(rec, t_intersection, ray, cylinder);
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
	else if (t1 < 0)
		t_intersection = t2;
	else if (t2 < 0)
		t_intersection = t1;
	else if (t1 < t2)
		t_intersection = t1;
	else
		t_intersection = t2;
	if (!is_point_in_height_range(vec3,
			vec3.ops->add(
				ray->origin, vec3.ops->mul(ray->direction, t_intersection)),
			cylinder))
		return (false);
	setup_hit_record_caps(rec, t_intersection, ray, cylinder);
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

static void	setup_hit_record_side(
			t_hit_record *rec, double t, t_ray *ray, t_obj *cylinder)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};
	t_vec3			oc;
	t_vec3			projection;

	rec->shoot_direction = ray->direction;
	rec->point = vec3.ops->add(ray->origin, vec3.ops->mul(ray->direction, t));
	oc = vec3.ops->sub(rec->point, cylinder->position);
	projection = vec3.ops->mul(
			cylinder->norm, vec3.ops->dot(oc, cylinder->norm));
	rec->norm = vec3.ops->sub(oc, projection);
	rec->norm = vec3.ops->div(rec->norm, cylinder->d_param1);
	rec->color = cylinder->color;
	rec->front_face = vec3.ops->dot(ray->direction, rec->norm) < 0;
	if (!rec->front_face)
		rec->norm = vec3.ops->mul(rec->norm, -1);
	rec->t = t;
}

static void	setup_hit_record_caps(
			t_hit_record *rec, double t, t_ray *ray, t_obj *cylinder)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};
	double			dot_product;

	rec->shoot_direction = ray->direction;
	rec->point = vec3.ops->add(ray->origin, vec3.ops->mul(ray->direction, t));
	rec->norm = cylinder->norm;
	rec->front_face = vec3.ops->dot(ray->direction, rec->norm) < 0;
	dot_product = vec3.ops->dot(ray->direction, cylinder->norm);
	if (dot_product > 0)
		rec->norm = vec3.ops->mul(rec->norm, -1);
	rec->color = cylinder->color;
	if (!rec->front_face)
		rec->norm = vec3.ops->mul(rec->norm, -1);
	rec->t = t;
}
