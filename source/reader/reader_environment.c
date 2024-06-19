/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_environment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:24:15 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/19 19:36:37 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_private.h"

static bool	parse_ambient(t_scene *scene, char **tokens);
static bool	parse_camera(t_scene *scene, char **tokens);
static bool	parse_light(t_scene *scene, char **tokens);

bool	parse_environment(t_scene *scene, char **tokens)
{
	if (ft_strcmp(tokens[0], "A") == 0)
	{
		if (!parse_ambient(scene, tokens + 1))
			return (false);
	}
	else if (ft_strcmp(tokens[0], "C") == 0)
	{
		if (!parse_camera(scene, tokens + 1))
			return (false);
	}
	else if (ft_strcmp(tokens[0], "L") == 0)
	{
		if (!parse_light(scene, tokens + 1))
			return (false);
	}
	return (true);
}

bool	parse_ambient(t_scene *scene, char **tokens)
{
	if (get_array_size(tokens) != 2)
		return (printf("parse_ambient: %s", INVALID_NUM_ARG), false);
	if (!is_valid_number(tokens[0]) || !is_valid_vector(tokens[1]))
		return (printf("parse_ambient: %s", INVALID_CONTENT_FMT), false);
	scene->amblight.ratio = ft_atof(tokens[0]);
	if (!parse_color_vector(&scene->amblight.color, tokens[1]))
		return (printf("parse_ambient: %s", FAILED_PARSE_VEC), false);
	return (true);
}

bool	parse_camera(t_scene *scene, char **tokens)
{
	if (get_array_size(tokens) != 3)
		return (printf("parse_camera: %s", INVALID_NUM_ARG), false);
	if (!is_valid_vector(tokens[0]) || \
		!is_valid_vector(tokens[1]) || !is_valid_number(tokens[2]))
		return (printf("parse_camera: %s", INVALID_CONTENT_FMT), false);
	if (!parse_vector(&scene->camera.position, tokens[0]))
		return (printf("parse_camera: %s", FAILED_PARSE_VEC), false);
	if (!parse_vector(&scene->camera.norm, tokens[1]))
		return (printf("parse_camera: %s", FAILED_PARSE_VEC), false);
	scene->camera.fov = ft_atof(tokens[2]);
	return (true);
}

bool	parse_light(t_scene *scene, char **tokens)
{
	if (get_array_size(tokens) != 3)
		return (printf("parse_light: %s", INVALID_NUM_ARG), false);
	if (!is_valid_vector(tokens[0]) || \
		!is_valid_number(tokens[1]) || !is_valid_vector(tokens[2]))
		return (printf("parse_light: %s", INVALID_CONTENT_FMT), false);
	if (!parse_vector(&scene->light.position, tokens[0]))
		return (printf("parse_light: %s", FAILED_PARSE_VEC), false);
	scene->light.ratio = ft_atof(tokens[1]);
	if (!parse_color_vector(&scene->light.color, tokens[2]))
		return (printf("parse_light: %s", FAILED_PARSE_VEC), false);
	return (true);
}
