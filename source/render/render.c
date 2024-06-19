/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:28:05 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/19 15:28:00 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

static void	render_pixel(t_scene *scene, t_ray *ray_pool);

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
			shoot_ray(scene->objects, &(ray_pool[i * pixel->col_size + j]));
			render_pixel(scene, &(ray_pool[i * pixel->col_size + j]));
			j++;
		}
		i++;
	}
}

void	render_pixel(t_scene *scene, t_ray *ray)
{
	t_list	*hit_record;

	hit_record = ray->hit_record_list;
	while (hit_record)
	{
		// TODO: Need to handle front_face == false
		ray->cache_color = compute_color(scene, hit_record->content);
		hit_record = hit_record->next;
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
	// TODO: Implemet shadow
	ambient_color = ambient(rec, &scene->amblight);
	diffuse_color = diffuse(rec, &scene->light);
	specular_color = specular(rec, &scene->light);
	color = vec3.ops->add(ambient_color, diffuse_color);
	color = vec3.ops->add(color, specular_color);
	return (color);
}
