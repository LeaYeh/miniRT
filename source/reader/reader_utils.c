/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:49:59 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/26 18:22:07 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_private.h"

bool	parse_vector(t_vec3 *v, char *str)
{
	char	*x;
	char	*y;
	char	*z;

	if (v == NULL || str == NULL)
		return (false);
	x = ft_strtok(str, ",");
	y = ft_strtok(NULL, ",");
	z = ft_strtok(NULL, WHITESPACE);
	if (ft_strtok(NULL, WHITESPACE) != NULL)
		return (false);
	*v = vector(ft_atof(x), ft_atof(y), ft_atof(z));
	return (true);
}

bool	parse_norm_vector(t_vec3 *v, char *str)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};

	if (!parse_vector(v, str))
		return (false);
	if (!is_in_range_vec3(v, -1.0, 1.0))
		return (false);
	if (fabs(vec3.ops->magnitude(*v)) < 1e-6)
		return (false);
	if (vec3.ops->magnitude(*v) == 1)
		return (true);
	*v = vec3.ops->normalize(*v);
	return (true);
}

bool	parse_color_vector(t_vec3 *v, char *str)
{
	const t_vec3	vec3 = (t_vec3){.ops = init_ops()};

	if (!parse_vector(v, str))
		return (false);
	if (!is_in_range_vec3(v, 0.0, 255.0))
		return (false);
	*v = vec3.ops->div(*v, 255);
	return (true);
}
