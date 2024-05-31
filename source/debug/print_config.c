/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:33:13 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/31 17:20:10 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_object(t_obj *object)
{
	printf("Object: %d\n", object->type);
	printf("\tPosition: ");
	print_vector(object->position);
	printf("\tNorm: ");
	print_vector(object->norm);
	printf("\tParam1: %f\n", object->d_param1);
	printf("\tParam2: %f\n", object->d_param2);
	printf("\tColor: ");
	print_vector(object->color);
}

void	print_camera(t_camera camera)
{
	printf("Camera:\n");
	printf("\tPosition: ");
	print_vector(camera.position);
	printf("\tNorm: ");
	print_vector(camera.norm);
	printf("\tFOV: %f\n", camera.fov);
}

void	print_light(t_light light)
{
	printf("Light:\n");
	printf("\tPosition: ");
	print_vector(light.position);
	printf("\tRatio: %f\n", light.ratio);
	printf("\tColor: ");
	print_vector(light.color);
}

void	print_amblight(t_amblight amblight)
{
	printf("Ambient Light:\n");
	printf("\tColor: ");
	print_vector(amblight.color);
	printf("\tRatio: %f\n", amblight.ratio);
}

void	print_scene(t_scene *sence)
{
	t_list	*obj_list;

	printf("\n==================== [Scene] ====================\n");
	print_amblight(sence->amblight);
	print_camera(sence->camera);
	print_light(sence->light);
	obj_list = sence->objects;
	while (obj_list)
	{
		print_object((t_obj *)obj_list->content);
		obj_list = obj_list->next;
	}
}
