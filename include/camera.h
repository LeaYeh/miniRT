/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:49:22 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/15 14:26:03 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "defines.h"
# include "vec3.h"
# include "ray.h"

typedef struct s_pixel_grid
{
	t_vec3	origin_corner;
	t_vec3	delta_u;
	t_vec3	delta_v;
	double	width;
	double	height;
}	t_pixel_grid;

typedef struct s_viewport
{
	t_vec3	origin_corner;
	t_vec3	v;
	t_vec3	u;
	t_vec3	w;
	double	width;
	double	height;
}	t_viewport;

typedef struct s_camera
{
	t_vec3			position;
	t_vec3			norm;
	double			fov;
	double			theta;
	double			focal_length;
	double			aspect_ratio;
	t_viewport		viewport;
	t_pixel_grid	pixel;
	t_ray			*ray_pool;
}	t_camera;

bool	init_camera(t_camera *camera);

#endif
