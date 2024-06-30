/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 01:01:57 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/30 19:49:55 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interact_private.h"

static bool	set_zoom(t_camera *camera, int key);
static bool	reset_camera(t_camera *camera, int key);

void	interact_camera(int key, t_minirt *minirt)
{
	if (set_rotation(&minirt->scene->camera.rotation, key) || \
		set_translation(&minirt->scene->camera.translation, key) || \
		set_zoom(&minirt->scene->camera, key) || \
		reset_camera(&minirt->scene->camera, key))
	{
		minirt->stage |= CAMERA_CHANGE;
	}
}

bool	set_zoom(t_camera *camera, int key)
{
	double	interval;

	interval = INTERVAL_FOV;
	if (*get_mod_key() & K_SHIFT)
		interval *= FACTOR_FAST;
	if (key == Button4)
		camera->fov = fmax(0, camera->fov - interval);
	else if (key == Button5)
		camera->fov = fmin(camera->fov + interval, 180.0);
	else
		return (false);
	return (true);
}

bool	reset_camera(t_camera *camera, int key)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};

	if (key == XK_space)
		camera->rotation = vector(0.0, 0.0, 0.0);
	else if (key == Button2)
		camera->fov = camera->org_fov;
	else if (key == XK_r)
	{
		if (vec3.ops->magnitude(camera->translation) == 0)
		{
			if (vec3.ops->magnitude(camera->rotation) == 0)
				camera->fov = camera->org_fov;
			camera->rotation = vector(0.0, 0.0, 0.0);
		}
		camera->translation = vector(0.0, 0.0, 0.0);
	}
	else
		return (false);
	return (true);
}
