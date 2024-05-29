/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:00:13 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/30 01:03:38 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "minirt.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc != 2)
	{
		printf("main: %s", INVALID_NUM_ARG);
		return (ERR_ARGC);
	}
	scene = read_scene(argv[1]);
	if (!scene)
		return (ERR_ARGC);
	print_scene(scene);
	// TODO: render_scene(scene);
	free_scene(&scene);
	return (SUCCESS);
}
