/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:00:13 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/29 20:38:48 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "minirt.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc != 2)
	{
		dprintf(2, "Error: Invalid number of arguments\n");
		return (ERR_ARGC);
	}
	scene = read_scene(argv[1]);
	if (!scene)
	{
		dprintf(2, "Error: Failed to read scene\n");
		return (ERR_ARGC);
	}
	print_scene(scene);
	// TODO: render_scene(scene);
	free_scene(&scene);
	return (SUCCESS);
}
