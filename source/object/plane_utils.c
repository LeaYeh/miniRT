/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:59:30 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/24 17:01:47 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_obj	init_plane(t_vec3 position, t_vec3 norm, t_vec3 color)
{
	t_obj	plane;

	plane.position = position;
	plane.norm = norm;
	plane.color = color;
	plane.type = PLANE;
	plane.d_param1 = 0;
	plane.d_param2 = 0;
	return (plane);
}
