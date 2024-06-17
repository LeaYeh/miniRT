/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:13:23 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/17 20:06:56 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_private.h"

static void		setup_viewport(t_camera *camera);
static void		setup_pixel_grid(t_camera *camera);
static bool		init_ray_pool(t_camera *camera);
static t_ray	get_ray(t_camera *camera, int px, int py);

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

void	setup_viewport(t_camera *camera)
{
	const t_vec3	world_up = (t_vec3){.x = 0, .y = 1, .z = 0};
	t_vec3			vec3;

	vec3 = (t_vec3){.ops = init_ops()};
	camera->viewport.height = 2 * tan(camera->theta / 2);
	camera->viewport.width = camera->aspect_ratio * camera->viewport.height;
	camera->viewport.w = vec3.ops->normalize(vec3.ops->mul(camera->norm, -1));
	camera->viewport.u = vec3.ops->normalize(
			vec3.ops->cross(world_up, camera->viewport.w));
	camera->viewport.v = vec3.ops->cross(
			camera->viewport.w, camera->viewport.u);
	camera->viewport.origin_corner = (t_vec3){
		.x = camera->position.x - camera->viewport.width / 2,
		.y = camera->position.y - camera->viewport.height / 2,
		.z = camera->position.z};
	camera->viewport.origin_corner = vec3.ops->add(
			camera->viewport.origin_corner,
			vec3.ops->mul(camera->viewport.w, camera->focal_length));
}

void	setup_pixel_grid(t_camera *camera)
{
	t_vec3			vec3;

	vec3 = (t_vec3){.ops = init_ops()};
	camera->pixel.width = camera->viewport.width / WINDOW_WIDTH;
	camera->pixel.height = camera->viewport.height / WINDOW_HEIGHT;
	camera->pixel.delta_u = vec3.ops->mul(
			camera->viewport.u, camera->pixel.width);
	camera->pixel.delta_v = vec3.ops->mul(
			camera->viewport.v, camera->pixel.height);
	camera->pixel.origin_corner = vec3.ops->sub(
			camera->viewport.origin_corner,
			vec3.ops->add(
				vec3.ops->mul(camera->viewport.u, camera->viewport.width / 2),
				vec3.ops->mul(camera->viewport.v, camera->viewport.height / 2))
			);
	camera->pixel.origin_corner = vec3.ops->sub(
			camera->pixel.origin_corner,
			vec3.ops->mul(camera->viewport.w, camera->focal_length));
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
			// TODO: How to avoid duplicate ray?
			camera->ray_pool[i * WINDOW_WIDTH + j] = get_ray(camera, j, i);
			j++;
		}
		i++;
	}
	return (true);
}

t_ray	get_ray(t_camera *camera, int px, int py)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};
	t_vec3			pixel_positon;

	pixel_positon = vec3.ops->add(
			camera->pixel.origin_corner,
			vec3.ops->add(
				vec3.ops->mul(camera->pixel.delta_u, px),
				vec3.ops->mul(camera->pixel.delta_v, py)));
	return ((t_ray){
		.origin = camera->position,
		.direction = vec3.ops->sub(pixel_positon, camera->position),
		.hit_record_list = NULL});
}

// bool	setup_ray(t_camera *camera, double u, double v)
// {
// 	t_vec3	vec3;
// 	t_ray	*ray;

// 	vec3 = (t_vec3){.ops = init_ops()};
// 	ray = (t_ray *)malloc(sizeof(t_ray));
// 	if (!ray)
// 		return (false);
// 	ray->origin = camera->position;
// 	ray->direction = vec3.ops->add(
// 			camera->viewport.origin_corner,
// 			vec3.ops->add(
// 				vec3.ops->mul(camera->viewport.u, u),
// 				vec3.ops->mul(camera->viewport.v, v)));
// 	ray->direction = vec3.ops->sub(ray->direction, camera->position);
// 	ray->direction = vec3.ops->sub(ray->direction, vec3.ops->mul(
// 				camera->viewport.w, camera->focal_length));
// 	if (!ft_lstnew_back(&camera->ray_list, ray))
// 		return (free(ray), false);
// 	return (true);
// }
