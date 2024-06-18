/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:57:25 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/18 15:47:19 by lyeh             ###   ########.fr       */
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
