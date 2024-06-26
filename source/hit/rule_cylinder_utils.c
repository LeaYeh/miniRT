/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_cylinder_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:38:11 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/24 21:26:35 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_private.h"

bool	is_point_in_cap_range(t_vec3 p,
			t_obj *cylinder, t_vec3 center_top, t_vec3 center_bottom)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};
	const double	radius = cylinder->d_param1 / 2.0;
	double			proj;
	double			dist;

	proj = vec3.ops->dot(vec3.ops->sub(p, center_top), cylinder->norm);
	dist = vec3.ops->magnitude(vec3.ops->sub(p, center_top));
	if (fabs(proj) < 1e-6 && dist <= radius)
		return (true);
	proj = vec3.ops->dot(vec3.ops->sub(p, center_bottom), cylinder->norm);
	dist = vec3.ops->magnitude(vec3.ops->sub(p, center_bottom));
	if (fabs(proj) < 1e-6 && dist <= radius)
		return (true);
	return (false);
}

bool	is_point_in_height_range(t_vec3 p, t_obj *cylinder)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};
	double			pc_proj;
	double			cy_proj_min;
	double			cy_proj_max;

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

bool	set_closest_hit(t_hit_record *rec,
				t_ray *ray, t_obj top_plane, t_obj bottom_plane)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};
	t_hit_record	top_rec;
	t_hit_record	bottom_rec;
	bool			hit_top;
	bool			hit_bottom;

	hit_top = hit_plane(vec3, ray, (t_obj *)&top_plane, &top_rec);
	hit_bottom = hit_plane(vec3, ray, (t_obj *)&bottom_plane, &bottom_rec);
	if (hit_top && hit_bottom)
	{
		if (is_min_positive_t(bottom_rec.t, top_rec.t))
			*rec = bottom_rec;
		else
			*rec = top_rec;
	}
	else if (hit_top)
		*rec = top_rec;
	else if (hit_bottom)
		*rec = bottom_rec;
	else
		return (false);
	return (true);
}
