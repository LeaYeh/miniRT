/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:36:14 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/31 16:51:43 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	init_minirt(t_minirt *minirt, char *filename)
{
	minirt->scene = read_scene(filename);
	if (!minirt->scene)
		return (false);
	return (true);
}

bool	free_minirt(t_minirt *minirt)
{
	free_scene(&minirt->scene);
	return (true);
}
