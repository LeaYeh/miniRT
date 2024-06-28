/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:10:23 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/25 19:03:35 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_PRIVATE_H
# define RENDER_PRIVATE_H

# include "render.h"
# include "camera.h"
# include "hit.h"
# include "vec3.h"

t_vec3	ambient(t_hit_record *rec, t_amblight *ambient_light);
t_vec3	diffuse(t_hit_record *rec, t_light *light);
t_vec3	specular(t_hit_record *rec, t_light *light);
bool	is_shadow(t_light light, t_list *object_list, t_hit_record rec);

#endif
