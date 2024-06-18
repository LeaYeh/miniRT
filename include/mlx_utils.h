#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "minirt.h"

bool	init_mlx(t_mlx *mlx);
void	img_pixel_put(t_img *img, int x, int y, int color);

#endif
