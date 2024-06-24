/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:30:43 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/23 20:08:03 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_private.h"

static void	setup_hit_record(
				t_hit_record *rec, double t, t_ray *ray, t_obj *obj);

/*
rec->point = P(t) = O + tD
rec->norm = (P - C) / r
*/
bool	hit_sphere(t_vec3 vec3, t_ray *ray, t_obj *sphere, t_hit_record *rec)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	t_intersection;

	oc = vec3.ops->sub(ray->origin, sphere->position);
	a = vec3.ops->dot(ray->direction, ray->direction);
	b = 2 * vec3.ops->dot(oc, ray->direction);
	c = vec3.ops->dot(oc, oc) - sphere->d_param1 * sphere->d_param1;
	t_intersection = calc_sphere_min_root(a, b, c);
	if (t_intersection < 0)
		return (false);
	setup_hit_record(rec, t_intersection, ray, sphere);
	return (true);
}

double	calc_sphere_min_root(double a, double b, double c)
{
	double	discriminant;
	double	sqrt_discriminant;
	double	t1;
	double	t2;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0 || fabs(a) < 1e-6)
		return (-1);
	sqrt_discriminant = sqrt(discriminant);
	t1 = (-b - sqrt_discriminant) / (2.0 * a);
	t2 = (-b + sqrt_discriminant) / (2.0 * a);
	if (t1 < 0 && t2 < 0)
		return (-1);
	else if (t1 < 0)
		return (t2);
	else if (t2 < 0)
		return (t1);
	else if (t1 < t2)
		return (t1);
	return (t2);
}

static void	setup_hit_record(
				t_hit_record *rec, double t, t_ray *ray, t_obj *obj)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};

	rec->shoot_direction = ray->direction;
	rec->point = vec3.ops->add(ray->origin, vec3.ops->mul(ray->direction, t));
	rec->norm = vec3.ops->div(
			vec3.ops->sub(rec->point, obj->position), obj->d_param1);
	rec->color = obj->color;
	rec->front_face = vec3.ops->dot(ray->direction, rec->norm) < 0;
	if (!rec->front_face)
		rec->norm = vec3.ops->mul(rec->norm, -1);
	rec->t = t;
}
