/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:49:59 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/29 21:32:35 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_private.h"

t_vec3	*parse_vector(char *str)
{
	t_vec3	*vec;
	char	**tokens;

	tokens = ft_split(str, ',');
	if (!tokens || get_array_size(tokens) != 3)
		return (NULL);
	vec = create_zero_vec3();
	if (!vec)
		return (free_array(tokens), NULL);
	vec->x = ft_atof(tokens[0]);
	vec->y = ft_atof(tokens[1]);
	vec->z = ft_atof(tokens[2]);
	return (free_array(tokens), vec);
}
