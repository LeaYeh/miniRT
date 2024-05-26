/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:19:11 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/26 12:05:44 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <stdlib.h>
# include <math.h>

typedef struct s_vector_3d
{
	double				x;
	double				y;
	double				z;
	struct s_vector_3d	*(*add)(struct s_vector_3d, struct s_vector_3d);
	struct s_vector_3d	*(*sub)(struct s_vector_3d, struct s_vector_3d);
	struct s_vector_3d	*(*mul)(struct s_vector_3d, double);
	struct s_vector_3d	*(*div)(struct s_vector_3d, double);
	struct s_vector_3d	*(*cross)(struct s_vector_3d, struct s_vector_3d);
	struct s_vector_3d	*(*normalize)(struct s_vector_3d);
	double				(*dot)(struct s_vector_3d, struct s_vector_3d);
	double				(*magnitude)(struct s_vector_3d);
}	t_vec3;

t_vec3	*create_vec3(double x, double y, double z);
t_vec3	*create_zero_vec3(void);

#endif
