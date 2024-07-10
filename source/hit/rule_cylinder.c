/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:35:18 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/29 21:16:25 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_private.h"

static bool	hit_cylinder_side(t_ray *ray, t_obj *cylinder, t_hit_record *rec);
static bool	hit_cylinder_caps(t_ray *ray, t_obj *cylinder, t_hit_record *rec);
static void	setup_hit_record_side(
				t_hit_record *rec, double t, t_ray *ray, t_obj *cylinder);
static void	setup_hit_record_caps(
				t_hit_record *rec, double t, t_ray *ray, t_obj *cylinder);

bool	hit_cylinder(t_ray *ray, t_obj *cylinder, t_hit_record *rec)
{
	bool			hit_side;
	bool			hit_caps;
	t_hit_record	rec_side;
	t_hit_record	rec_caps;

	hit_side = hit_cylinder_side(ray, cylinder, &rec_side);
	hit_caps = hit_cylinder_caps(ray, cylinder, &rec_caps);
	if (!hit_side && !hit_caps)
		return (false);
	else if (hit_side && !hit_caps)
		*rec = rec_side;
	else if (!hit_side && hit_caps)
		*rec = rec_caps;
	else if (is_min_positive_t(rec_side.t, rec_caps.t))
		*rec = rec_side;
	else
		*rec = rec_caps;
	return (true);
}

bool	hit_cylinder_side(t_ray *ray, t_obj *cylinder, t_hit_record *rec)
{
	const t_vec3	oc = vec3_sub(ray->origin, cylinder->position);
	double			a;
	double			b;
	double			c;
	double			t_intersection;

	a = vec3_dot(ray->direction, ray->direction) - \
			pow(vec3_dot(ray->direction, cylinder->norm), 2);
	b = 2 * (vec3_dot(oc, ray->direction) - \
			vec3_dot(ray->direction, cylinder->norm) * \
			vec3_dot(oc, cylinder->norm));
	c = vec3_dot(oc, oc) - \
			pow(vec3_dot(oc, cylinder->norm), 2) - \
			pow(cylinder->diameter / 2.0, 2);
	t_intersection = calc_sphere_min_root(a, b, c);
	if (t_intersection < 0)
		return (false);
	if (!is_point_in_height_range(
			vec3_add(ray->origin, vec3_mul(ray->direction, t_intersection)),
			cylinder))
		return (false);
	setup_hit_record_side(rec, t_intersection, ray, cylinder);
	return (true);
}

bool	hit_cylinder_caps(t_ray *ray, t_obj *cylinder, t_hit_record *rec)
{
	t_obj	top_plane;
	t_obj	bottom_plane;
	t_vec3	center_top;
	t_vec3	center_bottom;

	center_top = vec3_add(cylinder->position,
			vec3_mul(cylinder->norm, cylinder->height / 2));
	center_bottom = vec3_sub(cylinder->position,
			vec3_mul(cylinder->norm, cylinder->height / 2));
	top_plane = init_plane(center_top, cylinder->norm, cylinder->color);
	bottom_plane = init_plane(
			center_bottom, vec3_mul(cylinder->norm, -1), cylinder->color);
	if (!set_closest_hit(rec, ray, top_plane, bottom_plane))
		return (false);
	if (!is_point_in_cap_range(rec->point, cylinder, center_top, center_bottom))
		return (false);
	setup_hit_record_caps(rec, rec->t, ray, cylinder);
	return (true);
}

static void	setup_hit_record_side(
			t_hit_record *rec, double t, t_ray *ray, t_obj *cylinder)
{
	t_vec3	oc;
	t_vec3	projection;

	rec->shoot_direction = ray->direction;
	rec->point = vec3_add(ray->origin, vec3_mul(ray->direction, t));
	oc = vec3_sub(rec->point, cylinder->position);
	projection = vec3_mul(cylinder->norm, vec3_dot(oc, cylinder->norm));
	rec->norm = vec3_normalize(vec3_sub(oc, projection));
	rec->color = cylinder->color;
	rec->front_face = vec3_dot(ray->direction, rec->norm) < 0;
	if (!rec->front_face)
		rec->norm = vec3_mul(rec->norm, -1);
	rec->t = t;
}

static void	setup_hit_record_caps(
			t_hit_record *rec, double t, t_ray *ray, t_obj *cylinder)
{
	double	dot_product;

	rec->shoot_direction = ray->direction;
	rec->point = vec3_add(ray->origin, vec3_mul(ray->direction, t));
	if (vec3_dot(ray->direction, cylinder->norm) > 0)
		rec->norm = vec3_mul(cylinder->norm, -1);
	else
		rec->norm = cylinder->norm;
	rec->front_face = vec3_dot(ray->direction, rec->norm) < 0;
	dot_product = vec3_dot(ray->direction, cylinder->norm);
	if (dot_product > 0)
		rec->norm = vec3_mul(rec->norm, -1);
	rec->color = cylinder->color;
	rec->t = t;
}
