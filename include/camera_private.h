/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:38:42 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/18 12:51:20 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_PRIVATE_H
# define CAMERA_PRIVATE_H

# include "camera.h"

double	degree_to_radian(double degrees);
void	setup_viewport(t_camera *camera);
void	setup_pixel_grid(t_camera *camera);

#endif
