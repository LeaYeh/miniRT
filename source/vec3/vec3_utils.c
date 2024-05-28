/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:00:38 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/26 14:43:16 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3_private.h"

double	vec3_magnitude(t_vec3 a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_vec3	*vec3_normalize(t_vec3 a)
{
	t_vec3	*v;
	double	mag;

	v = create_zero_vec3();
	if (!v)
		return (NULL);
	mag = vec3_magnitude(a);
	v->x = a.x / mag;
	v->y = a.y / mag;
	v->z = a.z / mag;
	return (v);
}
