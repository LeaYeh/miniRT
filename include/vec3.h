/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:19:11 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/31 16:33:30 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <stdlib.h>
# include <math.h>

typedef struct s_vector_3d	t_vec3;

typedef struct s_vector_3d_ops
{
	t_vec3	(*add)(t_vec3, t_vec3);
	t_vec3	(*sub)(t_vec3, t_vec3);
	t_vec3	(*mul)(t_vec3, double);
	t_vec3	(*div)(t_vec3, double);
	t_vec3	(*cross)(t_vec3, t_vec3);
	t_vec3	(*normalize)(t_vec3);
	double	(*dot)(t_vec3, t_vec3);
	double	(*magnitude)(t_vec3);
}	t_vec3_ops;

typedef struct s_vector_3d
{
	double				x;
	double				y;
	double				z;
	const t_vec3_ops	*ops;
}	t_vec3;

#endif
