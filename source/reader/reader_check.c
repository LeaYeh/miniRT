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

bool	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (!ft_isdigit(str[i]) && \
			str[i] != '.' && str[i] != '-' && str[i] != '+')
			return (false);
		i++;
	}
	return (true);
}

bool	is_valid_vector(char *str)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (str[i] && str[i] != '\n')
	{
		if (!ft_isdigit(str[i]) && \
			str[i] != '.' && str[i] != '-' && str[i] != '+' && str[i] != ',')
			return (false);
		if (str[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (false);
	return (true);
}
