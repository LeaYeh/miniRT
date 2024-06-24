/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:22:39 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/24 17:24:48 by lyeh             ###   ########.fr       */
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

	if (get_array_size(tokens) != SPHERE_ARG_NUM)
		return (false);
	if (!is_valid_vector(tokens[0]) || \
		!is_valid_number(tokens[1]) || !is_valid_vector(tokens[2]))
		return (printf("parse_sphere: %s", INVALID_CONTENT_FMT), false);
	object = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (!object)
		return (false);
	object->type = SPHERE;
	object->d_param1 = ft_atof(tokens[1]);
	if (!parse_vector(&object->position, tokens[0]) || \
		!parse_color_vector(&object->color, tokens[2]))
		return (printf("parse_sphere: %s",
				FAILED_PARSE_VEC), free(object), false);
	if (!ft_lstnew_back(&scene->objects, object))
		return (printf("parse_sphere: %s", FAILED_ALLOC_MEM),
			free(object), false);
	return (true);
}

bool	parse_plane(t_scene *scene, char **tokens)
{
	t_obj	*object;

	if (get_array_size(tokens) != PLANE_ARG_NUM)
		return (printf("parse_plane: %s", INVALID_NUM_ARG), false);
	if (!is_valid_vector(tokens[0]) || \
		!is_valid_vector(tokens[1]) || !is_valid_vector(tokens[2]))
		return (printf("parse_plane: %s", INVALID_CONTENT_FMT), false);
	object = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (!object)
		return (printf("parse_plane: %s", FAILED_ALLOC_MEM), false);
	object->type = PLANE;
	if (!parse_vector(&object->position, tokens[0]) || \
		!parse_unit_vector(&object->norm, tokens[1]) || \
		!parse_color_vector(&object->color, tokens[2]))
		return (printf("parse_plane: %s", FAILED_PARSE_VEC),
			free(object), false);
	if (!ft_lstnew_back(&scene->objects, object))
		return (printf("parse_plane: %s", FAILED_ALLOC_MEM),
			free(object), false);
	return (true);
}

bool	parse_cylinder(t_scene *scene, char **tokens)
{
	t_obj	*object;

	if (get_array_size(tokens) != CYLINDER_ARG_NUM)
		return (printf("parse_cylinder: %s", INVALID_NUM_ARG), false);
	if (!is_valid_vector(tokens[0]) || !is_valid_vector(tokens[1]) || \
		!is_valid_number(tokens[2]) || !is_valid_number(tokens[3]) || \
		!is_valid_vector(tokens[4]))
		return (printf("parse_cylinder: %s", INVALID_CONTENT_FMT), false);
	object = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (!object)
		return (printf("parse_cylinder: %s", FAILED_ALLOC_MEM), false);
	object->type = CYLINDER;
	object->d_param1 = ft_atof(tokens[2]);
	object->d_param2 = ft_atof(tokens[3]);
	object->translation = vector(0.0, 0.0, 0.0);
	object->rotation = vector(0.0, 0.0, 0.0);
	if (!parse_vector(&object->position, tokens[0]) || \
		!parse_unit_vector(&object->norm, tokens[1]) || \
		!parse_color_vector(&object->color, tokens[4]))
		return (printf("parse_cylinder: %s", FAILED_PARSE_VEC),
			free(object), false);
	if (!ft_lstnew_back(&scene->objects, object))
		return (printf("parse_cylinder: %s", FAILED_ALLOC_MEM),
			free(object), false);
	return (true);
}
