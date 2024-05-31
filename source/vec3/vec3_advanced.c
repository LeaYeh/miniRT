/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_advanced.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:57:40 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/30 19:16:55 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3_private.h"

double	vec3_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec3	*vec3_cross(t_vec3 a, t_vec3 b)
{
	t_vec3	*v;

	v = create_zero_vec3();
	if (!v)
		return (NULL);
	v->x = a.y * b.z - a.z * b.y;
	v->y = a.z * b.x - a.x * b.z;
	v->z = a.x * b.y - a.y * b.x;
	return (v);
}
