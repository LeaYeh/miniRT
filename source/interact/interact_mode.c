/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 01:16:13 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/29 15:38:27 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interact_private.h"

bool	set_interact_mode(t_interact_mode *mode, int key)
{
	if (key == XK_c)
	{
		printf("Switch to camera mode\n");
		*mode = CAMERA;
	}
	else if (key == XK_o)
	{
		printf("Switch to object mode\n");
		*mode = OBJECT;
	}
	else
		return (false);
	return (true);
}
