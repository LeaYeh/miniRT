/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:36:14 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/16 12:24:45 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "debug.h"

static bool	init_color_map(t_minirt *minirt);

bool	init_minirt(t_minirt *minirt, char *filename)
{
	minirt->scene = read_scene(filename);
	if (!minirt->scene)
		return (false);
	if (!init_camera(&minirt->scene->camera) || !init_color_map(minirt))
		return (false);
	print_camera_detail(minirt->scene->camera);
	print_pixel_grid(minirt->scene->camera.pixel);
	return (true);
}

bool	init_color_map(t_minirt *minirt)
{
	int	i;

	minirt->color_map = (t_vec3 *)malloc(
			sizeof(t_vec3) * WINDOW_WIDTH * WINDOW_HEIGHT);
	if (!minirt->color_map)
		return (false);
	i = 0;
	while (i < WINDOW_WIDTH * WINDOW_HEIGHT)
	{
		minirt->color_map[i] = (t_vec3){0, 0, 0};
		i++;
	}
	return (true);
}

void	free_minirt(t_minirt *minirt)
{
	ft_free_and_null((void **)&minirt->scene->camera.ray_pool);
	free_scene(&minirt->scene);
}
