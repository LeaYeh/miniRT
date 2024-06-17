/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:37:47 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/17 20:09:22 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec3.h"

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
	t_list	*hit_record_list;
}	t_ray;

#endif
