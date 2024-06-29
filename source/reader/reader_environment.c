/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_environment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:24:15 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/29 23:46:22 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_private.h"

static bool	parse_ambient(t_scene *scene);
static bool	parse_camera(t_scene *scene);
static bool	parse_light(t_scene *scene);

bool	parse_environment(t_scene *scene, char *id)
{
	if (ft_strcmp(id, "A") == 0)
	{
		if (!parse_ambient(scene))
			return (print_error(INVALID_AMB_FMT), false);
	}
	else if (ft_strcmp(id, "C") == 0)
	{
		if (!parse_camera(scene))
			return (print_error(INVALID_CAM_FMT), false);
	}
	else if (ft_strcmp(id, "L") == 0)
	{
		if (!parse_light(scene))
			return (print_error(INVALID_LIG_FMT), false);
	}
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
	scene->amblight.brightness = ft_atof(brightness);
	if (!parse_color_vector(&scene->amblight.color, color))
		return (false);
	return (true);
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
	if (!parse_vector(&scene->camera.org_position, position))
		return (false);
	if (!parse_unit_vector(&scene->camera.org_norm, norm))
		return (false);
	scene->camera.fov = ft_atof(fov);
	return (true);
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
	scene->light.brightness = ft_atof(brightness);
	if (!parse_color_vector(&scene->light.color, color))
		return (false);
	return (true);
}
