/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:56:53 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/30 19:17:04 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3_private.h"

t_vec3	*vec3_add(t_vec3 a, t_vec3 b)
{
	t_vec3	*v;

	v = create_zero_vec3();
	if (!v)
		return (v);
	v->x = a.x + b.x;
	v->y = a.y + b.y;
	v->z = a.z + b.z;
	return (v);
}

t_vec3	*vec3_sub(t_vec3 a, t_vec3 b)
{
	t_vec3	*v;

	v = create_zero_vec3();
	if (!v)
		return (NULL);
	v->x = a.x - b.x;
	v->y = a.y - b.y;
	v->z = a.z - b.z;
	return (v);
}

t_vec3	*vec3_mul(t_vec3 a, double scalar)
{
	t_vec3	*v;

	v = create_zero_vec3();
	if (!v)
		return (NULL);
	v->x = a.x * scalar;
	v->y = a.y * scalar;
	v->z = a.z * scalar;
	return (v);
}

t_vec3	*vec3_div(t_vec3 a, double scalar)
{
	t_vec3	*v;

	v = create_zero_vec3();
	if (!v)
		return (NULL);
	v->x = a.x / scalar;
	v->y = a.y / scalar;
	v->z = a.z / scalar;
	return (v);
}
