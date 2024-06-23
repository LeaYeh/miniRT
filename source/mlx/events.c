
#include "mlx_utils.h"

int	clean_and_exit(t_minirt *minirt)
{
	free_minirt(minirt);
	exit (0);
}

void	setup_event_hooks(t_minirt *minirt)
{
	mlx_hook(minirt->mlx.win_ptr,
		DestroyNotify, NoEventMask, clean_and_exit, minirt);
}
