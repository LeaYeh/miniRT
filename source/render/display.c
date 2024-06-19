#include "defines.h"
#include "minirt.h"
#include "mlx_utils.h"
#include "debug.h"

static int	get_pixel_color(t_ray *ray);

int	display(void *arg)
{
	t_minirt		*minirt;
	t_mlx			*mlx;
	t_pixel_grid	*pixel;
	int				x;
	int				y;

	minirt = (t_minirt *)arg;
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
	t_vec3	color;

	if (!ray->cache_color)
		return (0);
	color = *ray->cache_color;
	print_vector(color);
	return ((int)color.x << 16 | (int)color.y << 8 | (int)color.z);
}
