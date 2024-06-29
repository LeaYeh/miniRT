/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:10:04 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/29 23:46:22 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

t_vec3	ambient(t_hit_record *rec, t_amblight *ambient_light)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};
	t_vec3			color;

	color = vec3.ops->mul(
			vec3.ops->mul_components(rec->color, ambient_light->color),
			ambient_light->brightness);
	return (color);
}
