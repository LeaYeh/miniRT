/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:30:14 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/14 14:03:56 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

static t_vec3	*vec3_add(t_vec3 a, t_vec3 b);
// static t_vec3	*vec3_sub(t_vec3 a, t_vec3 b);
// static t_vec3	*vec3_mul(t_vec3 a, double scalar);
// static t_vec3	*vec3_div(t_vec3 a, double scalar);
// static double	vec3_dot(t_vec3 a, t_vec3 b);
// static t_vec3	*vec3_cross(t_vec3 a, t_vec3 b);
// static double	vec3_magnitude(t_vec3 a);
// static t_vec3	*vec3_normalize(t_vec3 a);

t_vec3	*create_vec3(double x, double y, double z)
{
	t_vec3	*v;

	v = (t_vec3 *)calloc(1, sizeof(t_vec3));
	if (!v)
		return (v);
	v->x = x;
	v->y = y;
	v->z = z;
	v->add = vec3_add;

	return (v);
}

t_vec3	*vec3_add(t_vec3 a, t_vec3 b)
{
	t_vec3	*v;

	v = (t_vec3 *)calloc(1, sizeof(t_vec3));
	if (!v)
		return (v);
	v->x = a.x + b.x;
	v->y = a.y + b.y;
	v->z = a.z + b.z;

	return (v);
}
