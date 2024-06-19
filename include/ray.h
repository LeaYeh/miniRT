/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:37:47 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/19 17:00:09 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec3.h"
# include "camera.h"

typedef struct s_camera	t_camera;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
	t_list	*hit_record_list;
	t_vec3	cache_color;
}	t_ray;

t_vec3	reflect_direction(t_vec3 shoot_dir, t_vec3 p_norm);

#endif
