#include "defines.h"
#include "minirt.h"

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
