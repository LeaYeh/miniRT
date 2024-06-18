/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:49:22 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/18 12:55:02 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "defines.h"
# include "vec3.h"
# include "ray.h"
# include "canva.h"

typedef struct s_viewport	t_viewport;
typedef struct s_pixel_grid	t_pixel_grid;
typedef struct s_ray		t_ray;

typedef struct s_camera
{
	t_vec3			position;
	t_vec3			norm;
	double			fov;
	double			theta;
	double			focal_length;
	double			aspect_ratio;
	t_vec3			translation;
	t_vec3			rotation;
	t_viewport		viewport;
	t_pixel_grid	pixel;
	t_ray			*ray_pool;
}	t_camera;

bool	init_camera(t_camera *camera);

#endif
