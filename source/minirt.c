/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:36:14 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/15 13:46:30 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "debug.h"

bool	init_minirt(t_minirt *minirt, char *filename)
{
	minirt->scene = read_scene(filename);
	if (!minirt->scene)
		return (false);
	if (!init_camera(&minirt->scene->camera))
		return (false);
	print_camera_detail(minirt->scene->camera);
	print_pixel_grid(minirt->scene->camera.pixel);
	return (true);
}

bool	free_minirt(t_minirt *minirt)
{
	free_scene(&minirt->scene);
	return (true);
}
