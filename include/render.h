/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:28:36 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/25 23:23:33 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "minirt.h"
# include "ray.h"
# include "canva.h"
# include "hit.h"

int		display(t_minirt *minirt);
int		render(t_minirt *minirt);
t_vec3	compute_color(t_scene *scene, t_hit_record *rec);

#endif
