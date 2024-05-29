/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:32:21 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/29 21:33:06 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_private.h"

static t_amblight	*init_amblight(void);
static t_camera		*init_camera(void);
static t_light		*init_light(void);

t_scene	*init_scene(void)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->amblight = init_amblight();
	scene->camera = init_camera();
	scene->light = init_light();
	if (!scene->amblight || !scene->camera || !scene->light)
		return (free_scene(&scene), NULL);
	scene->objects = NULL;
	return (scene);
}

t_amblight	*init_amblight(void)
{
	t_amblight	*amblight;

	amblight = (t_amblight *)malloc(sizeof(t_amblight));
	if (!amblight)
		return (NULL);
	amblight->ratio = 0.0;
	amblight->color = NULL;
	return (amblight);
}

t_camera	*init_camera(void)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->position = NULL;
	camera->norm = NULL;
	camera->fov = 0.0;
	return (camera);
}

t_light	*init_light(void)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->position = NULL;
	light->color = NULL;
	light->ratio = 0.0;
	return (light);
}
