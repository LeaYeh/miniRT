/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:13:23 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/18 16:07:23 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_private.h"

static bool		init_ray_pool(t_camera *camera);
static t_ray	get_ray_from_pixel_grid(t_camera *camera, int px, int py);

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
			camera->ray_pool[i * WINDOW_WIDTH + j] = \
				get_ray_from_pixel_grid(camera, j, i);
			j++;
		}
		i++;
	}
	return (true);
}

t_ray	get_ray_from_pixel_grid(t_camera *camera, int px, int py)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};
	t_vec3			pixel_positon;

	pixel_positon = vec3.ops->add(
			camera->pixel.pixel00,
			vec3.ops->add(
				vec3.ops->mul(camera->pixel.delta_u, px),
				vec3.ops->mul(camera->pixel.delta_v, py)));
	return ((t_ray){
		.origin = camera->position,
		.direction = vec3.ops->sub(pixel_positon, camera->position),
		.hit_record_list = NULL,
		.cache_color = NULL});
}
