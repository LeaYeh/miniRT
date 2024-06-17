/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:42:14 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/17 11:41:00 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_private.h"

void	setup_hit_record(t_hit_record *rec, double t, t_ray *ray, t_obj *obj)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};

	rec->point = vec3.ops->add(ray->origin, vec3.ops->mul(ray->direction, t));
	rec->norm = obj->norm;
	rec->color = obj->color;
	rec->front_face = vec3.ops->dot(ray->direction, rec->norm) < 0;
	if (!rec->front_face)
		rec->norm = vec3.ops->mul(rec->norm, -1);
	rec->t = t;
}
