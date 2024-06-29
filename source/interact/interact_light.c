/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 01:01:54 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/29 23:48:16 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interact_private.h"

static bool	set_brightness(double *brightness, int key);
static bool	reset_light(t_light *light, int key);

void	interact_light(int key, t_minirt *minirt)
{
	if (set_translation(&minirt->scene->light.translation, key) || \
		set_color(&minirt->scene->light.color, key) || \
		set_brightness(&minirt->scene->light.brightness, key) || \
		reset_light(&minirt->scene->light, key))
	{
		minirt->stage |= LIGHT_CHANGE;
	}
	else
		printf("key press: %x\n", key);
}

void	interact_amblight(int key, t_minirt *minirt)
{
	if (set_color(&minirt->scene->amblight.color, key) || \
		set_brightness(&minirt->scene->amblight.brightness, key))
	{
		minirt->stage |= LIGHT_CHANGE;
	}
	else
		printf("key press: %x\n", key);
}

bool	set_brightness(double *brightness, int key)
{
	double	interval;

	interval = INTERVAL_BRIGHTNESS;
	if (*get_mod_key() & K_SHIFT)
	{
		printf("Fast ");
		interval *= FACTOR_FAST;
	}
	if (key == Button4)
	{
		printf("Increase brightness\n");
		*brightness = fmin(*brightness + interval, 1.0);
	}
	else if (key == Button5)
	{
		printf("Decrease brightness\n");
		*brightness = fmax(0, *brightness - interval);
	}
	else
		return (false);
	return (true);
}

bool	reset_light(t_light *light, int key)
{
	if (key == XK_r)
	{
		printf("Reset light\n");
		light->translation = vector(0.0, 0.0, 0.0);
	}
	else
		return (false);
	return (true);
}
