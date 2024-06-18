#include "defines.h"
#include "minirt.h"
#include "mlx_utils.h"

int	mock_render(void *arg)
{
	t_minirt	*minirt;
	t_mlx		*mlx;
	int			x;
	int			y;

	minirt = (t_minirt *)arg;
	mlx = &minirt->mlx;
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			img_pixel_put(&mlx->img, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	return (0);
}
