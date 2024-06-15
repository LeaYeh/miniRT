/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:20:20 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/15 16:36:47 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_private.h"

static bool		hit_object(t_ray *ray, t_obj *obj, t_hit_record *rec);

bool	find_nearest_object(t_list *object_list, t_ray *ray, t_hit_record *rec)
{
	t_obj	*obj;

	while (object_list)
	{
		obj = object_list->content;
		if (hit_object(ray, obj, rec))
			return (true);
		object_list = object_list->next;
	}
	return (false);
}

bool	hit_object(t_ray *ray, t_obj *obj, t_hit_record *rec)
{
	const t_vec3	vec3 = {.ops = init_ops()};

	if (obj->type == SPHERE)
		return (hit_sphere(vec3, ray, obj, rec));
	else if (obj->type == PLANE)
		return (hit_plane(vec3, ray, obj, rec));
	else if (obj->type == CYLINDER)
		return (hit_cylinder(vec3, ray, obj, rec));
	return (false);
}
