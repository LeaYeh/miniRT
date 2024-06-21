/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:49:59 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/21 15:33:57 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_private.h"

bool	parse_vector(t_vec3 *v, char *str)
{
	char	**tokens;

	if (v == NULL || str == NULL)
		return (false);
	tokens = ft_split(str, ',');
	if (!tokens || get_array_size(tokens) != 3)
		return (false);
	*v = vector(ft_atof(tokens[0]), ft_atof(tokens[1]), ft_atof(tokens[2]));
	return (free_array(tokens), true);
}

bool	parse_color_vector(t_vec3 *v, char *str)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};

	if (!parse_vector(v, str))
		return (false);
	if (v->x < 0 || v->y < 0 || v->z < 0 || \
		v->x > 255 || v->y > 255 || v->z > 255)
		return (false);
	*v = vec3.ops->div(*v, 255);
	return (true);
}
