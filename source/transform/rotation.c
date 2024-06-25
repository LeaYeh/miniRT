/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 22:17:52 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/25 20:08:14 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

static void	rotate_x(t_vec3 *v, double angle);
static void	rotate_y(t_vec3 *v, double angle);
static void	rotate_z(t_vec3 *v, double angle);

void	rotate(t_vec3 *v, t_vec3 rotation)
{
	rotate_x(v, rotation.x);
	rotate_y(v, rotation.y);
	rotate_z(v, rotation.z);
}

static void	rotate_x(t_vec3 *v, double angle)
{
	double	y;
	double	z;

	y = v->y * cos(angle) - v->z * sin(angle);
	z = v->y * sin(angle) + v->z * cos(angle);
	v->y = y;
	v->z = z;
}

static void	rotate_y(t_vec3 *v, double angle)
{
	double	x;
	double	z;

	x = v->x * cos(angle) + v->z * sin(angle);
	z = -v->x * sin(angle) + v->z * cos(angle);
	v->x = x;
	v->z = z;
}

static void	rotate_z(t_vec3 *v, double angle)
{
	double	x;
	double	y;

	x = v->x * cos(angle) - v->y * sin(angle);
	y = v->x * sin(angle) + v->y * cos(angle);
	v->x = x;
	v->y = y;
}
