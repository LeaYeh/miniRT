/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:13:12 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/28 15:14:18 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_private.h"

static void	free_object(t_obj **object);

void	free_object_array(t_obj ***objects)
{
	int	i;

	i = 0;
	while ((*objects)[i])
	{
		free_object((t_obj **)(*objects)[i]);
		i++;
	}
	ft_free_and_null((void **)*objects);
}

void	free_object(t_obj **object)
{
	ft_free_and_null((void **)&(*object)->position);
	ft_free_and_null((void **)&(*object)->color);
	ft_free_and_null((void **)&(*object)->norm);
	ft_free_and_null((void **)object);
}
