/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:00:13 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/28 14:38:45 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	// TODO: render_scene(scene);
	return (SUCCESS);
}
