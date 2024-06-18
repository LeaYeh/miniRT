/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:57:25 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/18 12:52:10 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_private.h"

t_ray	ray(t_vec3 origin, t_vec3 direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	// ray->point_at_parameter = NULL;
	return (ray);
}

t_ray	get_ray(t_camera *camera, int px, int py)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};
	t_vec3			pixel_positon;

	pixel_positon = vec3.ops->add(
			camera->pixel.origin_corner,
			vec3.ops->add(
				vec3.ops->mul(camera->pixel.delta_u, px),
				vec3.ops->mul(camera->pixel.delta_v, py)));
	return ((t_ray){
		.origin = camera->position,
		.direction = vec3.ops->sub(pixel_positon, camera->position),
		.hit_record_list = NULL,
		.cache_color = NULL});
}
