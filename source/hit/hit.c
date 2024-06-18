/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:20:20 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/17 21:30:01 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_private.h"
#include "debug.h"

static bool	hit_object(t_ray *ray, t_obj *obj, t_hit_record *rec);
static bool	handle_hit_record(t_ray *ray, t_hit_record *new_rec);
static bool	is_closer_hit_point(t_vec3 origin, t_hit_record *old_rec, t_hit_record *new_rec);

bool	setup_nearest_object(t_list *object_list, t_ray *ray)
{
	t_obj			*obj;
	t_hit_record	*tmp_rec;

	tmp_rec = (t_hit_record *)malloc(sizeof(t_hit_record));
	if (!tmp_rec)
		return (false);
	while (object_list)
	{
		obj = object_list->content;
		if (hit_object(ray, obj, tmp_rec))
		{
			// TODO: need code review
			if (!handle_hit_record(ray, tmp_rec))
				return (free(tmp_rec), false);
		}
		object_list = object_list->next;
	}
	return (false);
}

bool	handle_hit_record(t_ray *ray, t_hit_record *new_rec)
{
	t_list	*tmp_node;

	if (ray->hit_record_list == NULL)
	{
		ray->hit_record_list = ft_lstnew(new_rec);
		if (!ray->hit_record_list)
			return (false);
	}
	else
	{
		tmp_node = ft_lstlast(ray->hit_record_list);
		if (is_closer_hit_point(ray->origin, tmp_node->content, new_rec))
		{
			free(tmp_node->content);
			tmp_node->content = new_rec;
		}
	}
	return (true);
}

bool	is_closer_hit_point(t_vec3 origin, t_hit_record *old_rec, t_hit_record *new_rec)
{
	const t_vec3	vec3 = {.ops = init_ops()};
	double			old_dist;
	double			new_dist;

	old_dist = vec3.ops->magnitude(
			vec3.ops->sub(old_rec->point, origin));
	new_dist = vec3.ops->magnitude(
			vec3.ops->sub(new_rec->point, origin));
	return (new_dist < old_dist);
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
