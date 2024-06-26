/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 22:25:03 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/26 10:14:49 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

t_vec3	translate(t_vec3 v, t_vec3 translation)
{
	t_vec3	result;

	result.x = v.x + translation.x;
	result.y = v.y + translation.y;
	result.z = v.z + translation.z;
	return (result);
}
