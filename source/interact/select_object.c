/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 01:30:53 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/29 16:43:01 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interact_private.h"

bool	select_object(int key, t_list_d *objects)
{
	if (key == XK_Tab || key == XK_o)
	{
		if (*get_mod_key() & K_SHIFT)
			select_previous_node(objects);
		else
			select_next_node(objects);
	}
	else if (key == XK_1)
		select_n_node(1, objects);
	else if (key == XK_2)
		select_n_node(2, objects);
	else if (key == XK_3)
		select_n_node(3, objects);
	else if (key == XK_4)
		select_n_node(4, objects);
	else if (key == XK_5)
		select_n_node(5, objects);
	else if (key == XK_6)
		select_n_node(6, objects);
	else if (key == XK_7)
		select_n_node(7, objects);
	else if (key == XK_8)
		select_n_node(8, objects);
	else if (key == XK_9)
		select_n_node(9, objects);
	else
		return (false);
	return (true);
}
