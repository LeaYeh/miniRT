/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:38:40 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/26 18:38:03 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include "camera.h"
#include "object.h"

static void	transform_light(t_light *light);
static void	transform_objects(t_list_d *object_list);

void	transform_scene(t_scene *scene)
{
	transform_camera(&scene->camera);
	transform_light(&scene->light);
	transform_objects(scene->objects);
}

void	transform_camera(t_camera *camera)
{
	camera->position = translate(camera->org_position, camera->translation);
	camera->norm = rotate(camera->org_norm, camera->rotation);
}

void	transform_light(t_light *light)
{
	light->position = translate(light->org_position, light->translation);
}

void	transform_objects(t_list_d *object_list)
{
	t_obj	*object;

	while (object_list)
	{
		object = object_list->content;
		object->position = translate(object->org_position, object->translation);
		if (object->type != SPHERE)
			object->norm = rotate(object->org_norm, object->rotation);
		object_list = object_list->next;
	}
}
