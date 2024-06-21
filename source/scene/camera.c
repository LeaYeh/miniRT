/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:13:23 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/21 15:28:39 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_private.h"

bool	init_camera(t_camera *camera)
{
	camera->theta = degree_to_radian(camera->fov);
	camera->focal_length = 1.0;
	camera->aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	camera->translation = vector(0.0, 0.0, 0.0);
	camera->rotation = vector(0.0, 0.0, 0.0);
	setup_viewport(camera);
	setup_pixel_grid(camera);
	return (true);
}
