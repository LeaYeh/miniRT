/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:40:04 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/29 15:40:15 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

bool	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (false);
	mlx->win_ptr = mlx_new_window(
			mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");
	if (!mlx->win_ptr)
		return (false);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!mlx->img.img_ptr)
		return (false);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bits_per_pixel, &mlx->img.size_line, &mlx->img.endian);
	if (!mlx->img.addr)
		return (false);
	return (true);
}

int	clean_and_exit(t_minirt *minirt)
{
	mlx_destroy_window(minirt->mlx.mlx_ptr, minirt->mlx.win_ptr);
	mlx_destroy_image(minirt->mlx.mlx_ptr, minirt->mlx.img.img_ptr);
	mlx_destroy_display(minirt->mlx.mlx_ptr);
	free(minirt->mlx.mlx_ptr);
	free_minirt(minirt);
	exit (0);
}
