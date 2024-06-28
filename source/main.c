/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:00:13 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/25 16:22:21 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "minirt.h"
#include "mlx_utils.h"
#include "render.h"

int	main(int argc, char *argv[])
{
	t_minirt	minirt;

	if (argc != 2)
	{
		printf("main: %s", INVALID_NUM_ARG);
		return (ERR_ARGC);
	}
	if (!init_minirt(&minirt, argv[1]))
		return (free_minirt(&minirt), ERR_INIT);
	if (!init_mlx(&minirt.mlx))
		return (free_minirt(&minirt), ERR_INIT);
	print_scene(minirt.scene);
	setup_event_hooks(&minirt);
	mlx_loop_hook(minirt.mlx.mlx_ptr, render, &minirt);
	mlx_loop(minirt.mlx.mlx_ptr);
	free_minirt(&minirt);
	return (SUCCESS);
}
