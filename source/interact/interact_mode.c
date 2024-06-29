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

bool	switch_interact_mode(t_interact_mode *mode, int key)
{
	if (key == XK_c && *mode != CAMERA)
	{
		printf("Switch to camera mode\n");
		*mode = CAMERA;
	}
	else if (key == XK_o && *mode != OBJECT)
	{
		printf("Switch to object mode\n");
		*mode = OBJECT;
	}
	else if (key == XK_l)
	{
		if (*get_mod_key() & K_CTRL && *mode != AMBLIGHT)
		{
			printf("Switch to ambient light mode\n");
			*mode = AMBLIGHT;
		}
		else if (!(*get_mod_key() & K_CTRL) && *mode != LIGHT)
		{
			printf("Switch to light mode\n");
			*mode = LIGHT;
		}
		else
			return (false);
	}
	else
		return (false);
	return (true);
}
