/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:00:38 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/31 16:27:03 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3_private.h"

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
