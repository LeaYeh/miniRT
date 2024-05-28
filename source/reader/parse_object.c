/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:22:39 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/28 10:26:38 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_private.h"

static bool parse_sphere(t_scene *scene, char **tokens);
static bool parse_plane(t_scene *scene, char **tokens);
static bool parse_cylinder(t_scene *scene, char **tokens);

bool	parse_object(t_scene *scene, char **tokens)
{
	if (ft_strcmp(tokens[0], "sp") == 0)
	{
		if (!parse_sphere(scene, tokens))
			return (false);
	}
	else if (ft_strcmp(tokens[0], "pl") == 0)
	{
		if (!parse_plane(scene, tokens))
			return (false);
	}
	else if (ft_strcmp(tokens[0], "cy") == 0)
	{
		if (!parse_cylinder(scene, tokens))
			return (false);
	}
	return (true);
}

bool parse_sphere(t_scene *scene, char **tokens)
{
	(void)scene;
	(void)tokens;
	return (true);
}

bool parse_plane(t_scene *scene, char **tokens)
{
    (void)scene;
    (void)tokens;
    return (true);
}

bool parse_cylinder(t_scene *scene, char **tokens)
{
    (void)scene;
    (void)tokens;
    return (true);
}
