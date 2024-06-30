/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:30:43 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/29 21:16:07 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_private.h"

static void	setup_hit_record(
				t_hit_record *rec, double t, t_ray *ray, t_obj *obj);

/*
rec->point = P(t) = O + tD
rec->norm = (P - C) / r
*/
bool	hit_sphere(t_ray *ray, t_obj *sphere, t_hit_record *rec)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	t_intersection;

	oc = vec3_sub(ray->origin, sphere->position);
	a = vec3_dot(ray->direction, ray->direction);
	b = 2 * vec3_dot(oc, ray->direction);
	c = vec3_dot(oc, oc) - sphere->diameter * sphere->diameter;
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
	return (min_positive_t(t1, t2));
}

static void	setup_hit_record(
				t_hit_record *rec, double t, t_ray *ray, t_obj *obj)
{
	rec->shoot_direction = ray->direction;
	rec->point = vec3_add(ray->origin, vec3_mul(ray->direction, t));
	rec->norm = vec3_div(vec3_sub(rec->point, obj->position), obj->diameter);
	rec->color = obj->color;
	rec->front_face = vec3_dot(ray->direction, rec->norm) < 0;
	if (!rec->front_face)
		rec->norm = vec3_mul(rec->norm, -1);
	rec->t = t;
}
