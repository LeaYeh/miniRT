#include "minirt.h"

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	int		bytes_per_pixel;
	int		i;
	int		next_byte;
	char	*pixel;

	bytes_per_pixel = img->bits_per_pixel / 8;
	pixel = img->addr + (y * img->size_line + x * bytes_per_pixel);
	if (img->endian)
	{
		i = img->bits_per_pixel - 8;
		next_byte = -8;
	}
	else
	{
		i = 0;
		next_byte = 8;
	}
	while (bytes_per_pixel--)
	{
		*pixel++ = (color >> i) & 0XFF;
		i += next_byte;
	}
}
