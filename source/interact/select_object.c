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
		{
			printf("Previous object\n");
			select_previous_node(objects);
		}
		else
		{
			printf("Next object\n");
			select_next_node(objects);
		}
	}
	else if (key == XK_1)
	{
		printf("Select object 1\n");
		select_n_node(1, objects);
	}
	else if (key == XK_2)
	{
		printf("Select object 2\n");
		select_n_node(2, objects);
	}
	else if (key == XK_3)
	{
		printf("Select object 3\n");
		select_n_node(3, objects);
	}
	else if (key == XK_4)
	{
		printf("Select object 4\n");
		select_n_node(4, objects);
	}
	else if (key == XK_5)
	{
		printf("Select object 5\n");
		select_n_node(5, objects);
	}
	else if (key == XK_6)
	{
		printf("Select object 6\n");
		select_n_node(6, objects);
	}
	else if (key == XK_7)
	{
		printf("Select object 7\n");
		select_n_node(7, objects);
	}
	else if (key == XK_8)
	{
		printf("Select object 8\n");
		select_n_node(8, objects);
	}
	else if (key == XK_9)
	{
		printf("Select object 9\n");
		select_n_node(9, objects);
	}
	else
		return (false);
	return (true);
}