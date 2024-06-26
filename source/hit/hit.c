/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:20:20 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/26 16:07:56 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_private.h"
#include "debug.h"

static bool		recursive_ray(t_list *object_list,
					t_ray *root_ray, t_ray *cur_ray, int expect_depth);
static bool		handle_hit_record(
					t_ray *ray, t_hit_record *rec, const int expect_depth);
static bool		setup_infinite_record(t_ray *ray);
static t_ray	get_reflected_ray(t_hit_record rec);

bool	shoot_ray(void *param, t_ray *ray)
{
	t_list	*object_list;

	object_list = param;
	if (ft_lstsize(object_list) != 0 && ft_lstsize(ray->hit_record_list) == 0)
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
	t_hit_record	tmp_rec;
	t_list			*obj_node;
	t_ray			reflected_ray;

	obj_node = object_list;
	while (obj_node)
	{
		if (hit_object(cur_ray, obj_node->content, &tmp_rec))
			if (!handle_hit_record(root_ray, &tmp_rec, expect_depth))
				return (false);
		obj_node = obj_node->next;
	}
	if (ft_lstsize(root_ray->hit_record_list) == expect_depth && \
		ft_lstsize(root_ray->hit_record_list) < MAX_DEPTH)
	{
		reflected_ray = get_reflected_ray(tmp_rec);
		if (!recursive_ray(object_list,
				root_ray, &reflected_ray, expect_depth + 1))
			return (false);
	}
	return (true);
}

bool	handle_hit_record(t_ray *ray, t_hit_record *rec, int expect_depth)
{
	t_hit_record	*new_rec;
	t_list			*tmp_node;
	double			old_t;

	// init hit_record for first hit in this recursion
	if (ft_lstsize(ray->hit_record_list) < expect_depth)
	{
		new_rec = (t_hit_record *)malloc(sizeof(t_hit_record));
		if (!new_rec)
			return (false);
		*new_rec = *rec;
		if (!ft_lstnew_back(&(ray->hit_record_list), new_rec))
			return (free(new_rec), false);
	}
	// replace hit_record if new hit is closer in this recursion
	else
	{
		tmp_node = ft_lstlast(ray->hit_record_list);
		old_t = ((t_hit_record *)tmp_node->content)->t;
		if (is_min_positive_t(rec->t, old_t))
		{
			*((t_hit_record *)tmp_node->content) = *rec;
		}
	}
	return (true);
}

t_ray	get_reflected_ray(t_hit_record rec)
{
	t_ray			reflected_ray;

	reflected_ray = init_ray(
			rec.point,
			reflect_direction(
				rec.shoot_direction,
				rec.norm));
	return (reflected_ray);
}

bool	setup_infinite_record(t_ray *ray)
{
	t_hit_record	rec;

	rec.point = vector(0, 0, 0);
	rec.norm = vector(0, 0, 0);
	rec.color = vector(0, 0, 0);
	rec.front_face = false;
	rec.t = INFINITY;
	if (!handle_hit_record(ray, &rec, 1))
		return (false);
	return (true);
}
