/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:36:14 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/26 18:28:35 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "debug.h"

static bool		init_ray_pool(t_ray **ray_pool, t_camera *camera);
static t_ray	create_ray_from_pixel_grid(t_camera *camera, int row, int col);

bool	init_minirt(t_minirt *minirt, char *filename)
{
	minirt->scene = read_scene(filename);
	if (!minirt->scene)	//TODO: Check clean exit here
		return (false);
	printf("haha 0\n");
	init_camera(&minirt->scene->camera);
	printf("haha 1\n");
	if (!init_ray_pool(&minirt->ray_pool, &minirt->scene->camera))
		return (false);
	printf("haha 2\n");
	minirt->stage = CAMERA_CHANGE;
	minirt->mod_key = 0;
	print_camera_detail(minirt->scene->camera);
	printf("haha 3\n");
	return (true);
}

void	free_minirt(t_minirt *minirt)
{
	int	i;
	int	ray_amount;

	ray_amount = minirt->scene->camera.pixel.row_size * \
		minirt->scene->camera.pixel.col_size;
	i = 0;
	while (i < ray_amount)
	{
		ft_lstclear(&minirt->ray_pool[i].hit_record_list, free);
		i++;
	}
	ft_free_and_null((void **)&minirt->ray_pool);
	free_scene(&minirt->scene);
}

void	reset_ray_pool(t_ray *ray_pool, t_camera *camera)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	while (i < camera->pixel.row_size)
	{
		j = 0;
		while (j < camera->pixel.col_size)
		{
			index = i * camera->pixel.col_size + j;
			ft_lstclear(&ray_pool[index].hit_record_list, free);
			ray_pool[index] = create_ray_from_pixel_grid(camera, i, j);
			j++;
		}
		i++;
	}
}

bool	init_ray_pool(t_ray **ray_pool, t_camera *camera)
{
	int	i;
	int	j;

	*ray_pool = (t_ray *)malloc(
			sizeof(t_ray) * camera->pixel.col_size * camera->pixel.row_size);
	if (!*ray_pool)
		return (false);
	i = 0;
	while (i < camera->pixel.row_size)
	{
		j = 0;
		while (j < camera->pixel.col_size)
		{
			(*ray_pool)[i * camera->pixel.col_size + j] = \
				create_ray_from_pixel_grid(camera, i, j);
			j++;
		}
		i++;
	}
	return (true);
}

t_ray	create_ray_from_pixel_grid(t_camera *camera, int row, int col)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};
	t_vec3			pixel_positon;

	pixel_positon = get_pixel_position(camera->pixel, row, col);
	return (init_ray(camera->position,
			vec3.ops->normalize(
				vec3.ops->sub(pixel_positon, camera->position))));
}
