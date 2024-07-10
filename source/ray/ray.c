/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:57:25 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/30 20:18:59 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

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
	t_vec3	reflect;

	reflect = vec3_normalize(
			vec3_sub(shoot_dir,
				vec3_mul(p_norm, 2 * vec3_dot(shoot_dir, p_norm))));
	return (reflect);
}
