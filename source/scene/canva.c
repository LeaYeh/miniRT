/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canva.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:26:09 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/18 15:44:18 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canva.h"
#include "camera.h"

static void	setup_viewport_origin_corner(t_camera *camera);

void	setup_viewport(t_camera *camera)
{
	const t_vec3	world_up = (t_vec3){.x = 0, .y = 1, .z = 0};
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};

	camera->viewport.height = 2 * tan(camera->theta / 2);
	camera->viewport.width = camera->aspect_ratio * camera->viewport.height;
	camera->viewport.w = vec3.ops->normalize(vec3.ops->mul(camera->norm, -1));
	camera->viewport.u = vec3.ops->normalize(
			vec3.ops->cross(world_up, camera->viewport.w));
	camera->viewport.v = vec3.ops->cross(
			camera->viewport.w, camera->viewport.u);
	setup_viewport_origin_corner(camera);
}

void	setup_viewport_origin_corner(t_camera *camera)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};
	t_vec3			*origin_corner;
	t_viewport		*viewport;

	viewport = &camera->viewport;
	origin_corner = &viewport->origin_corner;
	*origin_corner = vec3.ops->add(
			camera->position,
			vec3.ops->add(
				vec3.ops->mul(viewport->u, -viewport->width / 2),
				vec3.ops->mul(viewport->v, -viewport->height / 2)));
	*origin_corner = vec3.ops->add(
			*origin_corner,
			vec3.ops->mul(viewport->w, camera->focal_length));
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
	camera->pixel.pixel00 = vec3.ops->sub(
			camera->viewport.origin_corner,
			vec3.ops->add(
				vec3.ops->mul(camera->viewport.u, camera->viewport.width / 2),
				vec3.ops->mul(camera->viewport.v, camera->viewport.height / 2))
			);
	camera->pixel.pixel00 = vec3.ops->sub(
			camera->pixel.pixel00,
			vec3.ops->mul(camera->viewport.w, camera->focal_length));
}