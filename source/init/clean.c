/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:04:15 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/30 19:40:38 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx_utils.h"

static void	free_ray_pool(t_ray **ray_pool, t_pixel_grid *pixel);

void	free_minirt(t_minirt *minirt)
{
	free_mlx(&minirt->mlx);
	if (minirt->scene)
	{
		free_ray_pool(&minirt->ray_pool, &minirt->scene->camera.pixel);
		free_scene(&minirt->scene);
	}
}

void	free_ray_pool(t_ray **ray_pool, t_pixel_grid *pixel)
{
	int	i;
	int	j;

	if (!*ray_pool)
		return ;
	i = 0;
	while (i < pixel->row_size)
	{
		j = 0;
		while (j < pixel->col_size)
		{
			ft_lstclear(
				&(*ray_pool)[i * pixel->col_size + j].hit_record_list, free);
			j++;
		}
		i++;
	}
	ft_free_and_null((void **)ray_pool);
}
