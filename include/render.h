/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:28:36 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/18 19:45:07 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "minirt.h"
# include "ray.h"
# include "canva.h"
# include "hit.h"

int		display(t_minirt *minirt);
void	render(t_scene *scene, t_pixel_grid *pixel, t_ray *ray_pool);
t_vec3	compute_color(t_scene *scene, t_hit_record *rec);

#endif
