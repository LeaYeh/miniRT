/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 01:01:52 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/29 15:37:43 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interact_private.h"

static bool	reset_object(t_obj *obj, int key);

void	interact_object(int key, t_minirt *minirt)
{
	t_obj	*obj;

	obj = get_selected_object(minirt->scene->objects);
	if (select_object(key, minirt->scene->objects))
		return ;
	else if (set_rotation(&obj->rotation, key) || \
		set_translation(&obj->translation, key) || \
		set_color(&obj->color, key) || \
		reset_object(obj, key))
	{
		minirt->stage |= OBJECT_CHANGE;
	}
	else
		printf("key press: %x\n", key);
}

bool	reset_object(t_obj *obj, int key)
{
	if (key == XK_space)
	{
		printf("Reset object orientation\n");
		obj->rotation = vector(0.0, 0.0, 0.0);
	}
	else if (key == XK_r)
	{
		printf("Reset object\n");
		obj->translation = vector(0.0, 0.0, 0.0);
		obj->rotation = vector(0.0, 0.0, 0.0);
	}
	else
		return (false);
	return (true);
}
