/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:42:14 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/29 21:16:07 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_private.h"
#include "debug.h"

// void	setup_hit_record(t_hit_record *rec, double t, t_ray *ray, t_obj *obj)
// {
// 	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};
// 	t_vec3			oc;
// 	t_vec3			projection;

// 	rec->shoot_direction = ray->direction;
// 	rec->point = vec3.ops->add(ray->origin, vec3.ops->mul(ray->direction, t));
// 	if (obj->type == PLANE)
// 		rec->norm = obj->norm;
// 	else if (obj->type == SPHERE)
// 		rec->norm = vec3.ops->div(
// 				vec3.ops->sub(rec->point, obj->position), obj->diameter);
// 	else if (obj->type == CYLINDER)
// 	{
// 		oc = vec3.ops->sub(rec->point, obj->position);
// 		projection = vec3.ops->mul(obj->norm, vec3.ops->dot(oc, obj->norm));
// 		rec->norm = vec3.ops->sub(oc, projection);
// 		rec->norm = vec3.ops->div(rec->norm, obj->diameter);
// 	}
// 	rec->color = obj->color;
// 	rec->front_face = vec3.ops->dot(ray->direction, rec->norm) < 0;
// 	if (!rec->front_face)
// 		rec->norm = vec3.ops->mul(rec->norm, -1);
// 	rec->t = t;
// }
