/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 21:00:37 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/29 23:10:05 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

static int	handle_keypress_event(int key, t_minirt *minirt);
static int	handle_keyrelease_event(int key, t_minirt *minirt);
static int	handle_buttonpress_event(
				int button, int x, int y, t_minirt *minirt);
static int	clean_and_exit(t_minirt *minirt);

void	setup_event_hooks(t_minirt *minirt)
{
	mlx_hook(minirt->mlx.win_ptr,
		DestroyNotify, NoEventMask, clean_and_exit, minirt);
	mlx_hook(minirt->mlx.win_ptr,
		KeyPress, KeyPressMask, handle_keypress_event, minirt);
	mlx_hook(minirt->mlx.win_ptr,
		KeyRelease, KeyReleaseMask, handle_keyrelease_event, minirt);
	mlx_hook(minirt->mlx.win_ptr,
		ButtonPress, ButtonPressMask, handle_buttonpress_event, minirt);
}

int	handle_keypress_event(int key, t_minirt *minirt)
{
	static t_interact_mode	mode = CAMERA;

	if (key == XK_Escape)
		clean_and_exit(minirt);
	else if (!set_mod_key(key) && !switch_interact_mode(&mode, key))
	{
		if (mode == CAMERA)
			interact_camera(key, minirt);
		else if (mode == OBJECT)
			interact_object(key, minirt);
		else if (mode == LIGHT)
			interact_light(key, minirt);
		else if (mode == AMBLIGHT)
			interact_amblight(key, minirt);
	}
	return (0);
}

int	handle_keyrelease_event(int key, t_minirt *minirt)
{
	(void)minirt;
	release_mod_key(key);
	return (0);
}

int	handle_buttonpress_event(int button, int x, int y, t_minirt *minirt)
{
	(void)x;
	(void)y;
	interact_object(button, minirt);
	return (0);
}

int	clean_and_exit(t_minirt *minirt)
{
	free_minirt(minirt);
	exit (0);
}
