/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 01:01:54 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/29 15:37:43 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interact_private.h"

static bool	set_intensity(double *intensity, int key);

void	interact_light(int key, t_minirt *minirt)
{
	if (set_translation(&minirt->scene->light.translation, key) || \
		set_color(&minirt->scene->light.color, key) || \
		set_intensity(&minirt->scene->light.ratio, key))
	{
		minirt->stage |= LIGHT_CHANGE;
	}
	else
		printf("key press: %x\n", key);
}

void	interact_amblight(int key, t_minirt *minirt)
{
	if (set_color(&minirt->scene->amblight.color, key) || \
		set_intensity(&minirt->scene->amblight.ratio, key))
	{
		minirt->stage |= LIGHT_CHANGE;
	}
	else
		printf("key press: %x\n", key);
}

bool	set_intensity(double *intensity, int key)
{
	(void)intensity;
	(void)key;
	return (false);
}
