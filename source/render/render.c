/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:28:05 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/24 23:03:45 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

static void		render_pixel(t_scene *scene, t_ray *ray_pool);
static t_vec3	clamp_color(t_vec3 color);

void	render(t_scene *scene, t_pixel_grid *pixel, t_ray *ray_pool)
{
	int	i;
	int	j;

	i = 0;
	while (i < pixel->row_size)
	{
		j = 0;
		while (j < pixel->col_size)
		{
			// printf("current: %d %d\n", i, j);
			// if (i == pixel->row_size / 2 && j == pixel->col_size / 2)
			// 	printf("center\n");
			shoot_ray(scene->objects, &(ray_pool[i * pixel->col_size + j]));
			render_pixel(scene, &(ray_pool[i * pixel->col_size + j]));
			j++;
		}
		i++;
	}
}

void	render_pixel(t_scene *scene, t_ray *ray)
{
	t_list	*hit_rec_node;

	hit_rec_node = ray->hit_record_list;
	while (hit_rec_node)
	{
		ray->cache_color = compute_color(scene, hit_rec_node->content);
		hit_rec_node = hit_rec_node->next;
	}
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
