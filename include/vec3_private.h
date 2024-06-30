/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_private.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:03:30 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/30 20:16:49 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_PRIVATE_H
# define VEC3_PRIVATE_H

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
