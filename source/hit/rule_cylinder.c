/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:35:18 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/25 17:48:46 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_private.h"
#include "debug.h"

static bool	hit_cylinder_side(t_vec3 vec3,
				t_ray *ray, t_obj *cylinder, t_hit_record *rec);
static bool	hit_cylinder_caps(t_vec3 vec3,
				t_ray *ray, t_obj *cylinder, t_hit_record *rec);
static void	setup_hit_record_side(
				t_hit_record *rec, double t, t_ray *ray, t_obj *cylinder);
static void	setup_hit_record_caps(
				t_hit_record *rec, double t, t_ray *ray, t_obj *cylinder);

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
	else if (is_min_positive_t(rec_side.t, rec_caps.t))
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
	b = 2 * (vec3.ops->dot(oc, ray->direction) - \
			vec3.ops->dot(ray->direction, cylinder->norm) * \
			vec3.ops->dot(oc, cylinder->norm));
	c = vec3.ops->dot(oc, oc) - \
			pow(vec3.ops->dot(oc, cylinder->norm), 2) - \
			pow(cylinder->d_param1 / 2.0, 2);
	t_intersection = calc_sphere_min_root(a, b, c);
	if (t_intersection < 0)
		return (false);
	if (!is_point_in_height_range(
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
	t_obj	top_plane;
	t_obj	bottom_plane;
	t_vec3	center_top;
	t_vec3	center_bottom;

	center_top = vec3.ops->add(cylinder->position,
			vec3.ops->mul(cylinder->norm, cylinder->d_param2 / 2));
	center_bottom = vec3.ops->sub(cylinder->position,
			vec3.ops->mul(cylinder->norm, cylinder->d_param2 / 2));
	top_plane = init_plane(center_top, cylinder->norm, cylinder->color);
	bottom_plane = init_plane(center_bottom, vec3.ops->mul(cylinder->norm, -1),
			cylinder->color);
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
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};
	t_vec3			oc;
	t_vec3			projection;

	rec->shoot_direction = ray->direction;
	rec->point = vec3.ops->add(ray->origin, vec3.ops->mul(ray->direction, t));
	oc = vec3.ops->sub(rec->point, cylinder->position);
	projection = vec3.ops->mul(
			cylinder->norm, vec3.ops->dot(oc, cylinder->norm));
	rec->norm = vec3.ops->normalize(vec3.ops->sub(oc, projection));
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
	// if the ray is same direction as the normal of the cap, the dot product will be positive
	// if the ray is opposite direction as the normal of the cap, the dot product will be negative
	if (vec3.ops->dot(ray->direction, cylinder->norm) > 0)
		rec->norm = vec3.ops->mul(cylinder->norm, -1);
	else
		rec->norm = cylinder->norm;
	rec->front_face = vec3.ops->dot(ray->direction, rec->norm) < 0;
	dot_product = vec3.ops->dot(ray->direction, cylinder->norm);
	if (dot_product > 0)
		rec->norm = vec3.ops->mul(rec->norm, -1);
	rec->color = cylinder->color;
	rec->t = t;
}
