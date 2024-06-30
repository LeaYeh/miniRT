/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffusion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:15:47 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/19 15:30:06 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

/*
This function calculates the diffusion of the light source.
It takes a hit record and a light source as arguments.
Notes:
	* Simple way: only consider the light color but not hit point color.
	* Advanced way: consider both light color and hit point color.
*/
t_vec3	diffuse(t_hit_record *rec, t_light *light)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};
	t_vec3			light_direction;
	double			diffuse_factor;
	t_vec3			diffuse_color;

	light_direction = vec3.ops->normalize(
			vec3.ops->sub(light->position, rec->point));
	diffuse_factor = vec3.ops->dot(light_direction, rec->norm);
	diffuse_factor = fmaxf(diffuse_factor, 0);
	// TODO: All color vectors should be normalized.
	diffuse_color = vec3.ops->mul(
			vec3.ops->mul_components(light->color, rec->color), diffuse_factor);
	return (vec3.ops->mul(diffuse_color, light->brightness));
}
