/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 01:26:38 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/29 15:37:43 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interact_private.h"

bool	set_translation(t_vec3 *translation, int key)
{
	double	interval;

	interval = INTERVAL_TRANSLATE;
	if (*get_mod_key() & K_SHIFT)
	{
		printf("Fast ");
		interval *= FACTOR_FAST;
	}
	if (key == XK_w)
	{
		printf("Move forward\n");
		translation->z -= interval;
	}
	else if (key == XK_s)
	{
		printf("Move backward\n");
		translation->z += interval;
	}
	else if (key == XK_a)
	{
		printf("Move left\n");
		translation->x -= interval;
	}
	else if (key == XK_d)
	{
		printf("Move right\n");
		translation->x += interval;
	}
	else if (key == XK_e)
	{
		printf("Move up\n");
		translation->y += interval;
	}
	else if (key == XK_q)
	{
		printf("Move down\n");
		translation->y -= interval;
	}
	else
		return (false);
	return (true);
}

bool	set_rotation(t_vec3 *rotation, int key)
{
	double	interval;

	if (!(*get_mod_key() & K_ALT))
		return (false);
	interval = INTERVAL_ROTATE;
	if (*get_mod_key() & K_SHIFT)
	{
		printf("Fast ");
		interval *= FACTOR_FAST;
	}
	if (key == XK_w)
	{
		printf("Pitch down\n");
		rotation->x -= interval;
	}
	else if (key == XK_s)
	{
		printf("Pitch up\n");
		rotation->x += interval;
	}
	else if (key == XK_a)
	{
		printf("Yaw left\n");
		rotation->y += interval;
	}
	else if (key == XK_d)
	{
		printf("Yaw right\n");
		rotation->y -= interval;
	}
	else if (key == XK_q)
	{
		printf("Roll left\n");
		rotation->z -= interval;
	}
	else if (key == XK_e)
	{
		printf("Roll right\n");
		rotation->z += interval;
	}
	else
		return (false);
	return (true);
}
