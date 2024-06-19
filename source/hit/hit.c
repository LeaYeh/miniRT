/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:20:20 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/19 17:09:48 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_private.h"
#include "debug.h"

static bool		recursive_ray(t_list *object_list,
					t_ray *root_ray, t_ray *cur_ray, int expect_depth);
static bool		handle_hit_record(
					t_ray *ray, t_hit_record *new_rec, const int expect_depth);
static bool		setup_infinite_record(t_ray *ray);
static t_ray	get_reflected_ray(t_hit_record *rec);
// static bool	is_closer_hit_point(
// 				t_vec3 origin, t_hit_record *old_rec, t_hit_record *new_rec);

bool	shoot_ray(t_list *object_list, t_ray *ray)
{
	if (ft_lstsize(ray->hit_record_list) == 0)
		if (!recursive_ray(object_list, ray, ray, 1))
			return (false);
	if (ray->hit_record_list == NULL)
	{
		if (!setup_infinite_record(ray))
			return (false);
	}
	return (true);
}

bool	recursive_ray(t_list *object_list,
			t_ray *root_ray, t_ray *cur_ray, const int expect_depth)
{
	t_hit_record	*tmp_rec;
	t_list			*cur_node;
	t_ray			reflected_ray;

	tmp_rec = (t_hit_record *)malloc(sizeof(t_hit_record));
	if (!tmp_rec)
		return (false);
	cur_node = object_list;
	while (cur_node)
	{
		if (hit_object(cur_ray, cur_node->content, tmp_rec))
			if (!handle_hit_record(root_ray, tmp_rec, expect_depth))
				return (free(tmp_rec), false);
		cur_node = cur_node->next;
	}
	if (ft_lstsize(root_ray->hit_record_list) == expect_depth && \
		ft_lstsize(root_ray->hit_record_list) < MAX_DEPTH)
	{
		reflected_ray = get_reflected_ray(tmp_rec);
		if (!recursive_ray(object_list, root_ray, &reflected_ray, expect_depth + 1))
			return (free(tmp_rec), false);
	}
	return (true);
}

bool	handle_hit_record(t_ray *ray, t_hit_record *new_rec, int expect_depth)
{
	t_list	*tmp_node;

	// init hit_record for first hit in this recursion
	if (ft_lstsize(ray->hit_record_list) < expect_depth)
	{
		if (!ft_lstnew_back(&(ray->hit_record_list), new_rec))
			return (false);
	}
	// replace hit_record if new hit is closer in this recursion
	else
	{
		tmp_node = ft_lstlast(ray->hit_record_list);
		if (new_rec->t < ((t_hit_record *)tmp_node->content)->t)
		{
			free(tmp_node->content);
			tmp_node->content = new_rec;
		}
	}
	return (true);
}

t_ray	get_reflected_ray(t_hit_record *rec)
{
	t_ray			reflected_ray;

	reflected_ray = (t_ray){
		.origin = rec->point,
		.direction = reflect_direction(
			rec->shoot_direction,
			rec->norm),
		.hit_record_list = NULL,
		.cache_color = (t_vec3){0, 0, 0, NULL}};
	return (reflected_ray);
}

bool	setup_infinite_record(t_ray *ray)
{
	t_hit_record	*rec;

	rec = (t_hit_record *)malloc(sizeof(t_hit_record));
	if (!rec)
		return (false);
	rec->point = (t_vec3){.x = 0, .y = 0, .z = 0, NULL};
	rec->norm = (t_vec3){.x = 0, .y = 0, .z = 0, NULL};
	rec->color = (t_vec3){.x = 0, .y = 0, .z = 0, NULL};
	rec->front_face = false;
	rec->t = INFINITY;
	if (!handle_hit_record(ray, rec, 1))
		return (free(rec), false);
	return (true);
}

// bool	is_closer_hit_point(
// 			t_vec3 origin, t_hit_record *old_rec, t_hit_record *new_rec)
// {
// 	const t_vec3	vec3 = {.ops = init_ops()};
// 	double			old_dist;
// 	double			new_dist;

// 	old_dist = vec3.ops->magnitude(
// 			vec3.ops->sub(old_rec->point, origin));
// 	new_dist = vec3.ops->magnitude(
// 			vec3.ops->sub(new_rec->point, origin));
// 	return (new_dist < old_dist);
// }

// bool	shoot_ray(t_scene *scene, t_ray *root_ray, t_ray *cur_ray)
// {
// 	t_obj			*obj;
// 	t_hit_record	*tmp_rec;
// 	t_list			*cur_node;
// 	t_ray			reflected_ray;

// 	tmp_rec = (t_hit_record *)malloc(sizeof(t_hit_record));
// 	if (!tmp_rec)
// 		return (false);
// 	cur_node = scene->objects;
// 	while (cur_node)
// 	{
// 		obj = cur_node->content;
// 		if (hit_object(cur_ray, obj, tmp_rec))
// 			if (!handle_hit_record(root_ray, tmp_rec))
// 				return (free(tmp_rec), false);
// 		cur_node = cur_node->next;
// 	}
// 	if (root_ray->hit_record_list == NULL)
// 	{
// 		if (!setup_infinite_record(root_ray, tmp_rec))
// 			return (free(tmp_rec), false);
// 	}
// 	if (cur_ray->depth < MAX_DEPTH)
// 	{
// 		reflected_ray = get_reflected_ray(scene->light, cur_ray, tmp_rec);
// 		if (!shoot_ray(scene, root_ray, &reflected_ray))
// 			return (free(tmp_rec), false);
// 	}
// 	return (true);
// }
