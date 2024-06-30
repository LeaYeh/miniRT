/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:48:29 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/22 20:01:48 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

t_vec3	specular(t_hit_record *rec, t_light *light)
{
	t_vec3	view_direction;
	t_vec3	light_direction;
	double	specular_factor;
	t_vec3	specular_color;

	light_direction = vec3_normalize(vec3_sub(rec->point, light->position));
	view_direction = vec3_normalize(vec3_mul(rec->shoot_direction, -1));
	specular_factor = vec3_dot(
			reflect_direction(light_direction, rec->norm), view_direction);
	specular_factor = fmaxf(0.0, fminf(specular_factor, 1.0));
	specular_factor = pow(specular_factor, SHINYNESS);
	specular_color = vec3_mul(light->color, specular_factor);
	return (vec3_mul(specular_color, light->brightness));
}
