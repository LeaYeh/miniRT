/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 01:16:13 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/29 17:36:13 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interact_private.h"

t_interact_mode	*get_interact_mode(void)
{
	static t_interact_mode	mode = CAMERA;

	return (&mode);
}

bool	switch_interact_mode(int key)
{
	t_interact_mode	*mode;

	mode = get_interact_mode();
	if (key == XK_c && *mode != CAMERA)
		*mode = CAMERA;
	else if (key == XK_o && *mode != OBJECT)
		*mode = OBJECT;
	else if (key == XK_l)
	{
		if (*get_mod_key() & K_CTRL && *mode != AMBLIGHT)
			*mode = AMBLIGHT;
		else if (!(*get_mod_key() & K_CTRL) && *mode != LIGHT)
			*mode = LIGHT;
		else
			return (false);
	}
	else
		return (false);
	return (true);
}
