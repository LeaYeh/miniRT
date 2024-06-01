/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:49:59 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/31 17:24:01 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_private.h"

bool	parse_vector(
t_vec3 *v, char *str)
{
	char	**tokens;

	if (v == NULL || str == NULL)
		return (false);
	tokens = ft_split(str, ',');
	if (!tokens || get_array_size(tokens) != 3)
		return (false);
	*v = (t_vec3){.x = ft_atof(tokens[0]),
		.y = ft_atof(tokens[1]),
		.z = ft_atof(tokens[2])};
	return (free_array(tokens), true);
}
