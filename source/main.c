/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:00:13 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/01 11:15:04 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "minirt.h"

int	main(int argc, char **argv)
{
	t_minirt	minirt;

	if (argc != 2)
	{
		printf("main: %s", INVALID_NUM_ARG);
		return (ERR_ARGC);
	}
	if (!init_minirt(&minirt, argv[1]))
		return (ERR_INIT);
	print_scene(minirt.scene);
	free_minirt(&minirt);
	return (SUCCESS);
}
