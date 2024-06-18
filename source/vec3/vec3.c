/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:30:14 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/18 17:40:05 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3_private.h"

t_vec3_ops	*init_ops(void)
{
	static t_vec3_ops	ops = {
		.add = vec3_add,
		.sub = vec3_sub,
		.mul = vec3_mul,
		.div = vec3_div,
		.cross = vec3_cross,
		.normalize = vec3_normalize,
		.mul_components = vec3_mul_components,
		.dot = vec3_dot,
		.magnitude = vec3_magnitude
	};

	return (&ops);
}
