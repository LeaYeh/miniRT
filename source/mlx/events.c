
#include "mlx_utils.h"

int	clean_and_exit(t_minirt *minirt)
{
	free_minirt(minirt);
	exit (0);
}

int	handle_key_event(int keysym, t_minirt *minirt)
{
	if (keysym == XK_Escape)
		clean_and_exit(minirt);
	return (0);
}

void	setup_event_hooks(t_minirt *minirt)
{
	mlx_hook(minirt->mlx.win_ptr,
		DestroyNotify, NoEventMask, clean_and_exit, minirt);
	mlx_hook(minirt->mlx.win_ptr,
		KeyPress, KeyPressMask, handle_key_event, minirt);
}
