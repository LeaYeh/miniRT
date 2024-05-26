/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_private.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:03:30 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/26 12:06:31 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_PRIVATE_H
# define VEC3_PRIVATE_H

# include "vec3.h"

t_vec3	*vec3_add(t_vec3 a, t_vec3 b);
t_vec3	*vec3_sub(t_vec3 a, t_vec3 b);
t_vec3	*vec3_mul(t_vec3 a, double scalar);
t_vec3	*vec3_div(t_vec3 a, double scalar);
double	vec3_dot(t_vec3 a, t_vec3 b);
t_vec3	*vec3_cross(t_vec3 a, t_vec3 b);
double	vec3_magnitude(t_vec3 a);
t_vec3	*vec3_normalize(t_vec3 a);

#endif
