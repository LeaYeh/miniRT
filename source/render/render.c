/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:28:05 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/26 17:59:14 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"
#include "transform.h"

static bool		render_pixel(void *param, t_ray *ray_pool);
static t_vec3	clamp_color(t_vec3 color);

int	render(t_minirt *minirt)
{
	t_pixel_grid	*pixel;

	pixel = &minirt->scene->camera.pixel;
	transform_scene(minirt->scene);
	if (minirt->stage >= CAMERA_CHANGE)
	{
		setup_viewport(&minirt->scene->camera);
		setup_pixel_grid(&minirt->scene->camera);
		reset_ray_pool(minirt->ray_pool, &minirt->scene->camera);
	}
	if (minirt->stage >= OBJECT_CHANGE)
		if (!iter_pixels(
				minirt->scene->objects, pixel, minirt->ray_pool, shoot_ray))
			return (1);
	if (minirt->stage >= LIGHT_CHANGE)
		if (!iter_pixels(minirt->scene, pixel, minirt->ray_pool, render_pixel))
			return (1);
	if (minirt->stage > NO_CHANGE)
	{
		display(minirt);
		minirt->stage = NO_CHANGE;
	}
	return (0);
}

bool	iter_pixels(void *param,
			t_pixel_grid *pixel, t_ray *ray_pool, bool (*f)(void *, t_ray *))
{
	int	i;
	int	j;

	i = 0;
	while (i < pixel->row_size)
	{
		j = 0;
		while (j < pixel->col_size)
		{
			if (!f(param, &ray_pool[i * pixel->col_size + j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	render_pixel(void *param, t_ray *ray)
{
	t_scene	*scene;
	t_list	*hit_rec_node;

	scene = param;
	hit_rec_node = ray->hit_record_list;
	while (hit_rec_node)
	{
		ray->cache_color = compute_color(scene, hit_rec_node->content);
		hit_rec_node = hit_rec_node->next;
	}
	return (true);
}

t_vec3	compute_color(t_scene *scene, t_hit_record *rec)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};
	t_vec3			color;
	t_vec3			ambient_color;
	t_vec3			diffuse_color;
	t_vec3			specular_color;

	if (rec->t == INFINITY)
		return (scene->bg_color);
	else if (rec->front_face == false)
		return (vector(0, 0, 0));
	ambient_color = ambient(rec, &scene->amblight);
	if (is_shadow(scene->light, scene->objects, *rec))
		return (ambient_color);
	diffuse_color = diffuse(rec, &scene->light);
	specular_color = specular(rec, &scene->light);
	color = vec3.ops->add(ambient_color, diffuse_color);
	color = vec3.ops->add(color, specular_color);
	return (clamp_color(color));
}

static t_vec3	clamp_color(t_vec3 color)
{
	color.x = fminf(color.x, 1);
	color.y = fminf(color.y, 1);
	color.z = fminf(color.z, 1);
	return (color);
}
