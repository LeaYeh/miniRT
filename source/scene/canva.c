/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canva.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:26:09 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/30 19:23:26 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canva.h"
#include "camera.h"

static void	setup_viewport_origin_corner(t_camera *camera);

void	setup_viewport(t_camera *camera)
{
	const t_vec3	world_up = vector(0.0, 1.0, 0.0);

	camera->theta = degree_to_radian(camera->fov);
	camera->viewport.height = 2 * tan(camera->theta / 2);
	camera->viewport.width = camera->aspect_ratio * camera->viewport.height;
	camera->viewport.w = vec3_normalize(vec3_mul(camera->norm, -1));
	if (camera->norm.y == 1.0)
		camera->viewport.u = vector(1.0, 0.0, 0.0);
	else if (camera->norm.y == -1.0)
		camera->viewport.u = vector(-1.0, 0.0, 0.0);
	else
		camera->viewport.u = vec3_normalize(
				vec3_cross(world_up, camera->viewport.w));
	camera->viewport.v = vec3_cross(camera->viewport.u, camera->viewport.w);
	setup_viewport_origin_corner(camera);
}

void	setup_viewport_origin_corner(t_camera *camera)
{
	t_vec3		*origin_corner;
	t_viewport	*viewport;

	viewport = &camera->viewport;
	origin_corner = &viewport->origin_corner;
	*origin_corner = camera->position;
	*origin_corner = vec3_sub(
			*origin_corner,
			vec3_mul(viewport->u, viewport->width / 2));
	*origin_corner = vec3_sub(
			*origin_corner,
			vec3_mul(viewport->v, viewport->height / 2));
	*origin_corner = vec3_sub(
			*origin_corner,
			vec3_mul(viewport->w, camera->focal_length));
}

void	setup_pixel_grid(t_camera *camera)
{
	camera->pixel.width = camera->viewport.width / WINDOW_WIDTH;
	camera->pixel.height = camera->viewport.height / WINDOW_HEIGHT;
	camera->pixel.delta_u = vec3_mul(camera->viewport.u, camera->pixel.width);
	camera->pixel.delta_v = vec3_mul(camera->viewport.v, camera->pixel.height);
	camera->pixel.pixel00 = camera->viewport.origin_corner;
	camera->pixel.pixel00 = vec3_add(
			camera->pixel.pixel00,
			vec3_div(camera->pixel.delta_u, 2));
	camera->pixel.pixel00 = vec3_add(
			camera->pixel.pixel00,
			vec3_div(camera->pixel.delta_v, 2));
	camera->pixel.row_size = \
			(int)(camera->viewport.height / camera->pixel.height);
	camera->pixel.col_size = \
			(int)(camera->viewport.width / camera->pixel.width);
}

t_vec3	get_pixel_position(t_pixel_grid pixel, int row, int col)
{
	t_vec3	pixel_position;

	pixel_position = vec3_add(
			pixel.pixel00,
			vec3_add(
				vec3_mul(pixel.delta_u, col),
				vec3_mul(pixel.delta_v, row)));
	return (pixel_position);
}
