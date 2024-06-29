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

void	interact_light(int key, t_minirt *minirt)
{
	if (set_translation(&minirt->scene->light.translation, key) || \
		set_color(&minirt->scene->light.color, key) || \
		set_brightness(&minirt->scene->light.brightness, key))
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
	(void)brightness;
	(void)key;
	return (false);
}
