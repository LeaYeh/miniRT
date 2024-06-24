/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 01:23:27 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/23 08:36:37 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

bool	is_shadow(t_light light, t_list *object_list, t_hit_record rec)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};
	t_ray			shadow_ray;
	t_vec3			point2light;
	t_hit_record	tmp_rec;

	point2light = vec3.ops->sub(light.position, rec.point);
	shadow_ray = init_ray(
			vec3.ops->add(rec.point, vec3.ops->mul(rec.norm, 1e-3)),
			vec3.ops->normalize(point2light));
	while (object_list)
	{
		if (hit_object(&shadow_ray, object_list->content, &tmp_rec) && \
			is_min_positive_t(tmp_rec.t, vec3.ops->magnitude(point2light)))
			return (true);
		object_list = object_list->next;
	}
	return (false);
}
