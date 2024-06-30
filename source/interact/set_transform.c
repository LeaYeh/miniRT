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
		interval *= FACTOR_FAST;
	if (key == XK_w)
		translation->z -= interval;
	else if (key == XK_s)
		translation->z += interval;
	else if (key == XK_a)
		translation->x -= interval;
	else if (key == XK_d)
		translation->x += interval;
	else if (key == XK_e)
		translation->y += interval;
	else if (key == XK_q)
		translation->y -= interval;
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
		interval *= FACTOR_FAST;
	if (key == XK_w)
		rotation->x -= interval;
	else if (key == XK_s)
		rotation->x += interval;
	else if (key == XK_a)
		rotation->y += interval;
	else if (key == XK_d)
		rotation->y -= interval;
	else if (key == XK_q)
		rotation->z -= interval;
	else if (key == XK_e)
		rotation->z += interval;
	else
		return (false);
	return (true);
}
