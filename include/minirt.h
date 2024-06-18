/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:18:37 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/19 19:29:02 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "reader.h"
# include "environment.h"
# include "camera.h"
# include "utils.h"
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_mlx;

typedef struct s_minirt
{
	t_mlx	mlx;
	t_scene	*scene;
	t_ray	*ray_pool;
}	t_minirt;

bool	init_minirt(t_minirt *minirt, char *filename);
void	free_minirt(t_minirt *minirt);

#endif
