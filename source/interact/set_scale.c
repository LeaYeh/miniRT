/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:37:53 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/29 19:33:30 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interact_private.h"

bool	set_scale(t_obj *obj, int key)
{
	double	interval;

	interval = INTERVAL_SCALE;
	if (*get_mod_key() & K_SHIFT)
	{
		printf("Fast ");
		interval *= FACTOR_FAST;
	}
	if (key == Button4)
	{
		printf("Scale up\n");
		obj->diameter += interval;
		obj->height += interval;
	}
	else if (key == Button5)
	{
		printf("Scale down\n");
		obj->diameter -= interval;
		obj->height -= interval;
	}
	else
		return (false);
	return (true);
}
