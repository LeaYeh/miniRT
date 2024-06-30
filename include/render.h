/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:28:36 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/30 19:18:02 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "minirt.h"
# include "ray.h"
# include "canva.h"
# include "hit.h"

int		display(t_minirt *minirt);
int		render(t_minirt *minirt);
t_vec3	compute_color(t_scene *scene, t_hit_record *rec);
bool	iter_pixels(void *param,
			t_pixel_grid *pixel,
			t_ray *ray_pool,
			bool (*f)(void *, t_ray *));

#endif
