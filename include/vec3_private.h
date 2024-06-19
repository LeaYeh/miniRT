/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_private.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:03:30 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/18 17:40:27 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_PRIVATE_H
# define VEC3_PRIVATE_H

# include <stdbool.h>
# include "vec3.h"

t_vec3		vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3		vec3_sub(t_vec3 v1, t_vec3 v2);
t_vec3		vec3_mul(t_vec3 v, double scalar);
t_vec3		vec3_div(t_vec3 v, double scalar);
double		vec3_dot(t_vec3 v1, t_vec3 v2);
t_vec3		vec3_cross(t_vec3 v1, t_vec3 v2);
t_vec3		vec3_mul_components(t_vec3 v1, t_vec3 v2);
double		vec3_magnitude(t_vec3 v);
t_vec3		vec3_normalize(t_vec3 v);

#endif
