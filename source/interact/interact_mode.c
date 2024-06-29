/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 01:16:13 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/29 16:55:17 by ldulling         ###   ########.fr       */
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
	else
		return (false);
	return (true);
}
