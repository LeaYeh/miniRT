/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:20:20 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/01 12:12:02 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

static bool	hit_sphere(t_ray *ray, t_obj *sphere, t_hit_record *rec);
static bool	hit_plane(t_ray *ray, t_obj *plane, t_hit_record *rec);
static bool	hit_cylinder(t_ray *ray, t_obj *cylinder, t_hit_record *rec);

bool	hit_object(t_ray *ray, t_obj *obj, t_hit_record *rec)
{
	if (obj->type == SPHERE)
		return (hit_sphere(ray, obj, rec));
	else if (obj->type == PLANE)
		return (hit_plane(ray, obj, rec));
	else if (obj->type == CYLINDER)
		return (hit_cylinder(ray, obj, rec));
	return (false);
}

bool	hit_sphere(t_ray *ray, t_obj *sphere, t_hit_record *rec)
{
	(void)ray;
	(void)sphere;
	(void)rec;
	return (false);
}

bool	hit_plane(t_ray *ray, t_obj *plane, t_hit_record *rec)
{
	(void)ray;
	(void)plane;
	(void)rec;
	return (false);
}

bool	hit_cylinder(t_ray *ray, t_obj *cylinder, t_hit_record *rec)
{
	(void)ray;
	(void)cylinder;
	(void)rec;
	return (false);
}
