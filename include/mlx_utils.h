#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "minirt.h"

typedef enum e_modifier_key
{
	K_SHIFT	= 1 << 0,
	K_CTRL	= 1 << 1,
	K_ALT	= 1 << 2
}	t_mod_key;

bool	init_mlx(t_mlx *mlx);
void	img_pixel_put(t_img *img, int x, int y, int color);

void	setup_event_hooks(t_minirt *minirt);

#endif
