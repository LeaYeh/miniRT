/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:52:33 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/30 18:52:36 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "minirt.h"
#include "mlx_utils.h"

static int	get_pixel_color(t_ray *ray);

int	display(t_minirt *minirt)
{
	t_mlx			*mlx;
	t_pixel_grid	*pixel;
	int				x;
	int				y;

	mlx = &minirt->mlx;
	pixel = &minirt->scene->camera.pixel;
	y = 0;
	while (y < pixel->row_size)
	{
		x = 0;
		while (x < pixel->col_size)
		{
			img_pixel_put(&mlx->img, x, y,
				get_pixel_color(&minirt->ray_pool[y * pixel->col_size + x]));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	return (0);
}

static int	get_pixel_color(t_ray *ray)
{
	return ((int)(ray->cache_color.x * 255.0) << 16 | \
			(int)(ray->cache_color.y * 255.0) << 8 | \
			(int)(ray->cache_color.z * 255.0));
}
