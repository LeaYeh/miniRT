/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:22:39 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/29 21:16:25 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_private.h"

static bool	parse_sphere(t_obj *object);
static bool	parse_plane(t_obj *object);
static bool	parse_cylinder(t_obj *object);

bool	parse_object(t_scene *scene, char *id)
{
	t_obj	*object;

	object = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (!object)
		return (print_error(FAILED_ALLOC_MEM), false);
	if (ft_strcmp(id, "sp") == 0)
	{
		if (!parse_sphere(object))
			return (print_error(INVALID_SPH_FMT), free(object), false);
	}
	else if (ft_strcmp(id, "pl") == 0)
	{
		if (!parse_plane(object))
			return (print_error(INVALID_PLA_FMT), free(object), false);
	}
	else if (ft_strcmp(id, "cy") == 0)
	{
		if (!parse_cylinder(object))
			return (print_error(INVALID_CYL_FMT), free(object), false);
	}
	if (!ft_lstnew_back_d(&scene->objects, object))
		return (print_error(FAILED_ALLOC_MEM), free(object), false);
	return (true);
}

bool	parse_sphere(t_obj *object)
{
	char	*position;
	char	*diameter;
	char	*color;

	position = ft_strtok(NULL, WHITESPACE);
	diameter = ft_strtok(NULL, WHITESPACE);
	color = ft_strtok(NULL, WHITESPACE);
	if (ft_strtok(NULL, WHITESPACE) != NULL)
		return (false);
	if (!is_valid_vector(position) || \
		!is_valid_float(diameter) || !is_valid_vector(color))
		return (false);
	object->type = SPHERE;
	object->org_diameter = ft_atof(diameter);
	object->diameter = object->org_diameter;
	return (parse_vector(&object->org_position, position) && \
		parse_color_vector(&object->color, color));
}

bool	parse_plane(t_obj *object)
{
	char	*position;
	char	*norm;
	char	*color;

	position = ft_strtok(NULL, WHITESPACE);
	norm = ft_strtok(NULL, WHITESPACE);
	color = ft_strtok(NULL, WHITESPACE);
	if (ft_strtok(NULL, WHITESPACE) != NULL)
		return (false);
	if (!is_valid_vector(position) || \
		!is_valid_vector(norm) || !is_valid_vector(color))
		return (false);
	object->type = PLANE;
	return (parse_vector(&object->org_position, position) && \
		parse_norm_vector(&object->org_norm, norm) && \
		parse_color_vector(&object->color, color));
}

bool	parse_cylinder(t_obj *object)
{
	char	*position;
	char	*norm;
	char	*diameter;
	char	*height;
	char	*color;

	position = ft_strtok(NULL, WHITESPACE);
	norm = ft_strtok(NULL, WHITESPACE);
	diameter = ft_strtok(NULL, WHITESPACE);
	height = ft_strtok(NULL, WHITESPACE);
	color = ft_strtok(NULL, WHITESPACE);
	if (ft_strtok(NULL, WHITESPACE) != NULL)
		return (false);
	if (!is_valid_vector(position) || !is_valid_vector(norm) || \
		!is_valid_float(diameter) || !is_valid_float(height) || \
		!is_valid_vector(color))
		return (false);
	object->type = CYLINDER;
	object->org_diameter = ft_atof(diameter);
	object->diameter = object->org_diameter;
	object->org_height = ft_atof(height);
	object->height = object->org_height;
	return (parse_vector(&object->org_position, position) && \
		parse_norm_vector(&object->org_norm, norm) && \
		parse_color_vector(&object->color, color));
}
