/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:32:21 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/31 17:20:56 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_private.h"

t_scene	*init_scene(void)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->amblight = (t_amblight){
		.ratio = 0.0,
		.color = (t_vec3){0.0, 0.0, 0.0, NULL}};
	scene->camera = (t_camera){
		.position = (t_vec3){0.0, 0.0, 0.0, NULL},
		.norm = (t_vec3){0.0, 0.0, 0.0, NULL},
		.fov = 0.0};
	scene->light = (t_light){
		.position = (t_vec3){0.0, 0.0, 0.0, NULL},
		.color = (t_vec3){0.0, 0.0, 0.0, NULL},
		.ratio = 0.0};
	scene->objects = NULL;
	return (scene);
}
