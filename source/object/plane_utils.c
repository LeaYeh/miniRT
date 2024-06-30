/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:59:30 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/29 21:16:25 by ldulling         ###   ########.fr       */
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
	plane.diameter = 0;
	plane.height = 0;
	return (plane);
}
