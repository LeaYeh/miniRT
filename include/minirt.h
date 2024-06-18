/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:18:37 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/18 19:06:49 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "reader.h"
# include "environment.h"
# include "camera.h"
# include "utils.h"

typedef struct s_minirt
{
	t_scene	*scene;
	t_ray	*ray_pool;
	t_vec3	*color_map; // ray_pool->cache_color
}	t_minirt;

bool	init_minirt(t_minirt *minirt, char *filename);
void	free_minirt(t_minirt *minirt);

#endif
