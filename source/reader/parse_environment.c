/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_environment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:24:15 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/28 14:43:18 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_private.h"

static bool parse_ambient(t_scene *scene, char **tokens);
static bool parse_camera(t_scene *scene, char **tokens);
static bool parse_light(t_scene *scene, char **tokens);

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

bool parse_ambient(t_scene *scene, char **tokens)
{
	(void)scene;
	(void)tokens;
	return (true);
}

bool parse_camera(t_scene *scene, char **tokens)
{
    (void)scene;
    (void)tokens;
    return (true);
}

bool parse_light(t_scene *scene, char **tokens)
{
    (void)scene;
    (void)tokens;
    return (true);
}
