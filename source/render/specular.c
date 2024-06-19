/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:48:29 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/19 17:02:19 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

t_vec3	specular(t_hit_record *rec, t_light *light)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};
	t_vec3			view_direction;
	t_vec3			light_direction;
	double			specular_factor;
	t_vec3			specular_color;

	light_direction = vec3.ops->normalize(
			vec3.ops->sub(light->position, rec->point));
	view_direction = vec3.ops->normalize(
			vec3.ops->mul(rec->shoot_direction, -1));
	specular_factor = vec3.ops->dot(
			reflect_direction(light_direction, rec->norm), view_direction);
	specular_factor = fmaxf(specular_factor, 0);
	// TODO: All objects should have a shininess factor. Or hard code it.
	specular_factor = pow(specular_factor, 100);
	specular_color = vec3.ops->mul(
			vec3.ops->mul_components(light->color, rec->color),
			specular_factor);
	return (specular_color);
}
