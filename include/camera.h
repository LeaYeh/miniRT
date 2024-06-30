/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:49:22 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/30 19:27:47 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "defines.h"
# include "vec3.h"
# include "ray.h"
# include "canva.h"
# include "utils.h"

typedef struct s_viewport	t_viewport;
typedef struct s_pixel_grid	t_pixel_grid;
typedef struct s_ray		t_ray;

typedef struct s_camera
{
	bool			is_init;
	t_vec3			org_position;
	t_vec3			org_norm;
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

void	init_camera(t_camera *camera);
void	setup_viewport(t_camera *camera);
void	setup_pixel_grid(t_camera *camera);

#endif
