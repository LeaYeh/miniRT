/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:30:43 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/15 16:32:09 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_private.h"

static double	calc_sphere_min_root(double a, double b, double c);

/*
rec->point = P(t) = O + tD
rec->norm = (P - C) / r
*/
bool	hit_sphere(t_vec3 vec3, t_ray *ray, t_obj *sphere, t_hit_record *rec)
{
	t_vec3			oc;
	double			a;
	double			b;
	double			c;
	double			t;

	oc = vec3.ops->sub(ray->origin, sphere->position);
	a = vec3.ops->dot(ray->direction, ray->direction);
	b = 2 * vec3.ops->dot(oc, ray->direction);
	c = vec3.ops->dot(oc, oc) - sphere->d_param1 * sphere->d_param1;
	t = calc_sphere_min_root(a, b, c);
	if (t < 0)
		return (false);
	rec->ray = *ray;
	rec->point = vec3.ops->add(ray->origin,
			vec3.ops->mul(ray->direction, t));
	rec->norm = vec3.ops->div(
			vec3.ops->sub(rec->point, sphere->position), sphere->d_param1);
	rec->color = sphere->color;
	rec->front_face = vec3.ops->dot(ray->direction, rec->norm) < 0;
	if (!rec->front_face)
		rec->norm = vec3.ops->mul(rec->norm, -1);
	return (true);
}

double	calc_sphere_min_root(double a, double b, double c)
{
	double	discriminant;
	double	sqrt_discriminant;
	double	t1;
	double	t2;

	discriminant = b * b - 4 * a * c;
	sqrt_discriminant = sqrt(discriminant);
	t1 = (-b - sqrt_discriminant) / (2.0 * a);
	t2 = (-b + sqrt_discriminant) / (2.0 * a);
	if (t1 > 0)
		return (t1);
	return (t2);
}
