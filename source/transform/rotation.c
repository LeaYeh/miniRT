/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 22:17:52 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/26 10:11:05 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

static t_vec3	rotate_x(t_vec3 v, double angle);
static t_vec3	rotate_y(t_vec3 v, double angle);
static t_vec3	rotate_z(t_vec3 v, double angle);

t_vec3	rotate(t_vec3 v, t_vec3 rotation)
{
	t_vec3	result;

	result = rotate_x(v, rotation.x);
	result = rotate_y(result, rotation.y);
	result = rotate_z(result, rotation.z);
	result = vec3_normalize(result);
	return (result);
}

static t_vec3	rotate_x(t_vec3 v, double angle)
{
	const double	rad = angle * M_PI / 180.0;
	double			y;
	double			z;

	y = v.y * cos(rad) - v.z * sin(rad);
	z = v.y * sin(rad) + v.z * cos(rad);
	return (vector(v.x, y, z));
}

static t_vec3	rotate_y(t_vec3 v, double angle)
{
	const double	rad = angle * M_PI / 180.0;
	double			x;
	double			z;

	x = v.x * cos(rad) + v.z * sin(rad);
	z = -v.x * sin(rad) + v.z * cos(rad);
	return (vector(x, v.y, z));
}

static t_vec3	rotate_z(t_vec3 v, double angle)
{
	const double	rad = angle * M_PI / 180.0;
	double			x;
	double			y;

	x = v.x * cos(rad) - v.y * sin(rad);
	y = v.x * sin(rad) + v.y * cos(rad);
	return (vector(x, y, v.z));
}
