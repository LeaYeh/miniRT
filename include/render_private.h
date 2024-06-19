/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:10:23 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/19 15:28:05 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_PRIVATE_H
# define RENDERER_PRIVATE_H

# include "render.h"
# include "hit.h"
# include "vec3.h"

t_vec3	ambient(t_hit_record *rec, t_amblight *ambient_light);
t_vec3	diffuse(t_hit_record *rec, t_light *light);
t_vec3	specular(t_hit_record *rec, t_light *light);

#endif
