/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:13:23 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/18 12:54:43 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_private.h"

static bool		init_ray_pool(t_camera *camera);

bool	init_camera(t_camera *camera)
{
	camera->theta = degree_to_radian(camera->fov);
	camera->focal_length = 1.0;
	camera->aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	camera->translation = (t_vec3){0, 0, 0, NULL};
	camera->rotation = (t_vec3){0, 0, 0, NULL};
	setup_viewport(camera);
	setup_pixel_grid(camera);
	if (!init_ray_pool(camera))
		return (false);
	return (true);
}

bool	init_ray_pool(t_camera *camera)
{
	int	i;
	int	j;

	// printf("viewport.width: %f\n", camera->viewport.width);
	// printf("viewport.height: %f\n", camera->viewport.height);
	// printf("grid col count: %d\n", camera->viewport.width / camera->pixel.width);
	camera->ray_pool = (t_ray *)malloc(
			sizeof(t_ray) * WINDOW_WIDTH * WINDOW_HEIGHT);
	if (!camera->ray_pool)
		return (false);
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			// TODO: How to avoid duplicate ray?
			camera->ray_pool[i * WINDOW_WIDTH + j] = get_ray(camera, j, i);
			j++;
		}
		i++;
	}
	return (true);
}
