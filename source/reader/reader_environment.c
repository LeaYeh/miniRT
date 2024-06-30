/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_environment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:24:15 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/30 19:36:35 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_private.h"

static bool	parse_ambient(t_scene *scene);
static bool	parse_camera(t_scene *scene);
static bool	parse_light(t_scene *scene);

bool	parse_environment(t_scene *scene, char *id)
{
	if (!scene->amblight.is_init && ft_strcmp(id, "A") == 0)
	{
		if (!parse_ambient(scene))
			return (print_error(INVALID_AMB_FMT), false);
		scene->amblight.is_init = true;
	}
	else if (!scene->camera.is_init && ft_strcmp(id, "C") == 0)
	{
		if (!parse_camera(scene))
			return (print_error(INVALID_CAM_FMT), false);
		scene->camera.is_init = true;
	}
	else if (!scene->light.is_init && ft_strcmp(id, "L") == 0)
	{
		if (!parse_light(scene))
			return (print_error(INVALID_LIG_FMT), false);
		scene->light.is_init = true;
	}
	else
		return (print_error(MULTIPLE_UNIQ_ID), false);
	return (true);
}

bool	parse_ambient(t_scene *scene)
{
	char	*brightness;
	char	*color;

	brightness = ft_strtok(NULL, WHITESPACE);
	color = ft_strtok(NULL, WHITESPACE);
	if (ft_strtok(NULL, WHITESPACE) != NULL)
		return (false);
	if (!is_valid_float(brightness) || !is_valid_vector(color))
		return (false);
	scene->amblight.org_brightness = ft_atof(brightness);
	scene->amblight.brightness = scene->amblight.org_brightness;
	return (is_in_range_double(scene->amblight.org_brightness, 0.0, 1.0) && \
		parse_color_vector(&scene->amblight.color, color));
}

bool	parse_camera(t_scene *scene)
{
	char	*position;
	char	*norm;
	char	*fov;

	position = ft_strtok(NULL, WHITESPACE);
	norm = ft_strtok(NULL, WHITESPACE);
	fov = ft_strtok(NULL, WHITESPACE);
	if (ft_strtok(NULL, WHITESPACE) != NULL)
		return (false);
	if (!is_valid_vector(position) || \
		!is_valid_vector(norm) || !is_valid_float(fov))
		return (false);
	if (!parse_vector(&scene->camera.org_position, position) || \
		!parse_norm_vector(&scene->camera.org_norm, norm))
		return (false);
	scene->camera.org_fov = ft_atof(fov);
	scene->camera.fov = scene->camera.org_fov;
	return (is_in_range_double(scene->camera.fov, 0.0, 180.0));
}

bool	parse_light(t_scene *scene)
{
	char	*position;
	char	*brightness;
	char	*color;

	position = ft_strtok(NULL, WHITESPACE);
	brightness = ft_strtok(NULL, WHITESPACE);
	color = ft_strtok(NULL, WHITESPACE);
	if (ft_strtok(NULL, WHITESPACE) != NULL)
		return (false);
	if (!is_valid_vector(position) || \
		!is_valid_float(brightness) || !is_valid_vector(color))
		return (false);
	if (!parse_vector(&scene->light.org_position, position))
		return (false);
	scene->light.org_brightness = ft_atof(brightness);
	scene->light.brightness = scene->light.org_brightness;
	return (is_in_range_double(scene->light.org_brightness, 0.0, 1.0) && \
		parse_color_vector(&scene->light.color, color));
}
