/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:40:42 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/24 22:56:09 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_private.h"

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

double	min_positive_t(double t1, double t2)
{
	if (t1 < 0 && t2 < 0)
		return (-1);
	if (t1 < 0)
		return (t2);
	if (t2 < 0)
		return (t1);
	if (t1 < t2)
		return (t1);
	return (t2);
}

bool	is_min_positive_t(double this, double other)
{
	if (this < 0)
		return (false);
	else if (this < other)
		return (true);
	return (false);
}
