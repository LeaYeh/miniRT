/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:30:14 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/30 19:37:40 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3_private.h"

t_vec3	*create_vec3(double x, double y, double z)
{
	t_vec3	*v;

	v = (t_vec3 *)malloc(sizeof(t_vec3));
	if (!v)
		return (NULL);
	v->x = x;
	v->y = y;
	v->z = z;
	v->add = vec3_add;
	v->sub = vec3_sub;
	v->mul = vec3_mul;
	v->div = vec3_div;
	v->cross = vec3_cross;
	v->normalize = vec3_normalize;
	v->dot = vec3_dot;
	v->magnitude = vec3_magnitude;
	return (v);
}

t_vec3	*create_zero_vec3(void)
{
	return (create_vec3(0, 0, 0));
}
