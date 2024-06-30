/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:51:22 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/29 21:36:40 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_private.h"

bool	is_valid_filename(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (false);
	if (ft_strcmp(filename + len - 3, ".rt") != 0)
		return (false);
	return (true);
}

bool	is_valid_float(char *str)
{
	bool	saw_digit;
	int		i;

	if (!str)
		return (false);
	saw_digit = false;
	i = 0;
	if (ft_issign(str[i]))
		i++;
	if (!ft_isdigit(str[i]) && str[i] != '.')
		return (false);
	while (ft_isdigit(str[i]))
	{
		saw_digit = true;
		i++;
	}
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
	{
		saw_digit = true;
		i++;
	}
	if (!saw_digit || (str[i] && str[i] != '\n'))
		return (false);
	return (true);
}

bool	is_valid_vector(char *str)
{
	char	*element;
	int		i;

	if (!str)
		return (false);
	if (str[ft_strlen(str) - 1] == ',')
		return (false);
	i = 0;
	element = ft_strtok(str, ",");
	while (element)
	{
		if (!is_valid_float(element))
			return (false);
		i++;
		element = ft_strtok(NULL, ",");
		if (!element)
			break ;
		element[-1] = ',';
	}
	return (i == 3);
}

bool	is_in_range_double(double num, double min, double max)
{
	return (num >= min && num <= max);
}

bool	is_in_range_vec3(t_vec3 *v, double min, double max)
{
	return (is_in_range_double(v->x, min, max) && \
			is_in_range_double(v->y, min, max) && \
			is_in_range_double(v->z, min, max));
}
