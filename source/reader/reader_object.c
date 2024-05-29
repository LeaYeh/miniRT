/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:22:39 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/29 21:17:16 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_private.h"

static bool	parse_sphere(t_scene *scene, char **tokens);
static bool	parse_plane(t_scene *scene, char **tokens);
static bool	parse_cylinder(t_scene *scene, char **tokens);

bool	parse_object(t_scene *scene, char **tokens)
{
	if (ft_strcmp(tokens[0], "sp") == 0)
	{
		if (!parse_sphere(scene, tokens + 1))
			return (false);
	}
	else if (ft_strcmp(tokens[0], "pl") == 0)
	{
		if (!parse_plane(scene, tokens + 1))
			return (false);
	}
	else if (ft_strcmp(tokens[0], "cy") == 0)
	{
		if (!parse_cylinder(scene, tokens + 1))
			return (false);
	}
	return (true);
}

bool	parse_sphere(t_scene *scene, char **tokens)
{
	t_obj	*object;

	if (get_array_size(tokens) != 3)
		return (false);
	object = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (!object)
		return (false);
	object->type = SPHERE;
	object->position = parse_vector(tokens[0]);
	object->d_param1 = ft_atof(tokens[1]);
	object->color = parse_vector(tokens[2]);
	if (object->position == NULL || object->color == NULL)
		return (free_object(object), false);
	if (!ft_lstnew_back(&scene->objects, object))
		return (free_object(object), false);
	return (true);
}

bool	parse_plane(t_scene *scene, char **tokens)
{
	t_obj	*object;

	if (get_array_size(tokens) != 3)
		return (false);
	object = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (!object)
		return (false);
	object->type = PLANE;
	object->position = parse_vector(tokens[0]);
	object->norm = parse_vector(tokens[1]);
	object->color = parse_vector(tokens[2]);
	if (object->position == NULL || \
		object->color == NULL || object->norm == NULL)
		return (free_object(object), false);
	if (!ft_lstnew_back(&scene->objects, object))
		return (free_object(object), false);
	return (true);
}

bool	parse_cylinder(t_scene *scene, char **tokens)
{
	t_obj	*object;

	if (get_array_size(tokens) != 5)
		return (false);
	object = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (!object)
		return (false);
	object->type = CYLINDER;
	object->position = parse_vector(tokens[0]);
	object->norm = parse_vector(tokens[1]);
	object->d_param1 = ft_atof(tokens[2]);
	object->d_param2 = ft_atof(tokens[3]);
	object->color = parse_vector(tokens[4]);
	if (object->position == NULL || \
		object->color == NULL || object->norm == NULL)
		return (free_object(object), false);
	if (!ft_lstnew_back(&scene->objects, object))
		return (free_object(object), false);
	return (true);
}
