/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canva.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:29:46 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/18 17:05:27 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVA_H
# define CANVA_H

# include "vec3.h"

typedef struct s_viewport
{
	t_vec3	origin_corner;
	t_vec3	v;
	t_vec3	u;
	t_vec3	w;
	double	width;
	double	height;
}	t_viewport;

typedef struct s_pixel_grid
{
	t_vec3	pixel00;
	t_vec3	delta_u;
	t_vec3	delta_v;
	double	width;
	double	height;
	int		row_size;
	int		col_size;
}	t_pixel_grid;

t_vec3	get_pixel_position(t_pixel_grid pixel, int row, int col);

#endif
