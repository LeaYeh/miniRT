/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:32:21 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/21 15:50:17 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_private.h"

t_scene	*init_scene(void)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->bg_color = vector(0.0, 0.0, 0.0);
	scene->amblight = (t_amblight){0};
	scene->amblight = (t_amblight){
		.ratio = 0.0,
		.color = vector(0.0, 0.0, 0.0)};
	scene->camera = (t_camera){0};
	scene->camera = (t_camera){
		.position = vector(0.0, 0.0, 0.0),
		.norm = vector(0.0, 0.0, 0.0),
		.fov = 0.0};
	scene->light = (t_light){0};
	scene->light = (t_light){
		.position = vector(0.0, 0.0, 0.0),
		.color = vector(0.0, 0.0, 0.0),
		.ratio = 0.0};
	scene->objects = NULL;
	return (scene);
}
