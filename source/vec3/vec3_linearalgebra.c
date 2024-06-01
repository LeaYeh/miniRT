/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_linearalgebra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:57:40 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/01 18:18:42 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3_private.h"

double	vec3_dot(t_vec3 v1, t_vec3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec3	vec3_cross(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}

double	vec3_magnitude(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vec3	vec3_normalize(t_vec3 v)
{
	double	magnitude;
	t_vec3	result;

	magnitude = vec3_magnitude(v);
	result.x = v.x / magnitude;
	result.y = v.y / magnitude;
	result.z = v.z / magnitude;
	return (result);
}
