/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:54:31 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/26 10:13:43 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "vec3.h"

t_vec3	rotate(t_vec3 v, t_vec3 rotation);
t_vec3	translate(t_vec3 v, t_vec3 translation);

#endif
