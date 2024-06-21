/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:57:25 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/21 13:41:00 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_private.h"

t_ray	init_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	ray.hit_record_list = NULL;
	ray.cache_color = vector(0, 0, 0);
	return (ray);
}

t_vec3	reflect_direction(t_vec3 shoot_dir, t_vec3 p_norm)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};
	t_vec3			reflect;

	reflect = vec3.ops->sub(
			shoot_dir,
			vec3.ops->mul(p_norm, 2 * vec3.ops->dot(shoot_dir, p_norm)));
	return (reflect);
}
