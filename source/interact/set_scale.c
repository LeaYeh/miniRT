/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:37:53 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/29 22:08:16 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interact_private.h"

static bool	set_scale_sphere(t_obj *obj, int key, double interval);
static bool	set_scale_cylinder(t_obj *obj, int key, double interval);
static void	set_scale_cylinder_up(
				t_obj *obj, double interval, t_scale_mode mode);
static void	set_scale_cylinder_down(
				t_obj *obj, double interval, t_scale_mode mode);

bool	set_scale(t_obj *obj, int key)
{
	double	interval;

	interval = INTERVAL_SCALE;
	if (*get_mod_key() & K_SHIFT)
		interval *= FACTOR_FAST;
	if (obj->type == SPHERE)
		return (set_scale_sphere(obj, key, interval));
	else if (obj->type == CYLINDER)
		return (set_scale_cylinder(obj, key, interval));
	else
		return (false);
}

bool	set_scale_sphere(t_obj *obj, int key, double interval)
{
	if (key == Button4)
		obj->diameter += interval;
	else if (key == Button5)
		obj->diameter = fmax(0, obj->diameter - interval);
	else
		return (false);
	return (true);
}

bool	set_scale_cylinder(t_obj *obj, int key, double interval)
{
	static t_scale_mode	mode;

	if (key == Button1)
		mode = (mode + 1) % SCALE_MODE_COUNT;
	else if (key == Button3)
		mode = (mode - 1 + SCALE_MODE_COUNT) % SCALE_MODE_COUNT;
	else if (key == Button4)
		set_scale_cylinder_up(obj, interval, mode);
	else if (key == Button5)
		set_scale_cylinder_down(obj, interval, mode);
	else
		return (false);
	return (true);
}

void	set_scale_cylinder_up(t_obj *obj, double interval, t_scale_mode mode)
{
	if (mode == DIAMETER || mode == BOTH)
		obj->diameter += interval;
	if (mode == HEIGHT || mode == BOTH)
		obj->height += interval;
}

void	set_scale_cylinder_down(t_obj *obj, double interval, t_scale_mode mode)
{
	if (mode == DIAMETER)
		obj->diameter = fmax(0, obj->diameter - interval);
	else if (mode == HEIGHT)
		obj->height = fmax(0, obj->height - interval);
	else if (mode == BOTH)
	{
		obj->diameter -= interval;
		obj->height -= interval;
		if (obj->diameter < 0)
		{
			obj->height += -obj->diameter;
			obj->diameter = 0;
		}
		else if (obj->height < 0)
		{
			obj->diameter += -obj->height;
			obj->height = 0;
		}
	}
}
