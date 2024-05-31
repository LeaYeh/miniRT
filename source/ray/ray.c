/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:57:25 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/31 11:26:08 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_private.h"

t_ray	*create_ray(t_vec3 *origin, t_vec3 *direction)
{
	t_ray	*ray;

	if (!origin || !direction)
		return (NULL);
	ray = (t_ray *)malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->origin = origin;
	ray->direction = direction;
	ray->point_at_parameter = NULL;
	return (ray);
}

// bool	hit_object(t_ray *ray, t_obj *obj, t_hit_record *rec)
// {
// 	if (obj->type == SPHERE)
// 		return (hit_sphere(ray, obj, rec));
// 	else if (obj->type == PLANE)
// 		return (hit_plane(ray, obj, rec));
// 	else if (obj->type == CYLINDER)
// 		return (hit_cylinder(ray, obj, rec));
// 	return (false);
// }

// bool	hit_sphere(t_ray *ray, t_obj *sphere, t_hit_record *rec)
// {
// }
