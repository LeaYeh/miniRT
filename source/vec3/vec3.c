/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:30:14 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/24 17:22:21 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vector(double x, double y, double z)
{
	return ((t_vec3){x, y, z});
}

t_vec3	unit_vector(double x, double y, double z)
{
	return (vec3_normalize(vector(x, y, z)));
}
