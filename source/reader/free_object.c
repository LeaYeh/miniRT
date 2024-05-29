/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:13:12 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/29 21:19:44 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_private.h"

void	free_object(t_obj *object)
{
	if (!object)
		return ;
	ft_free_and_null((void **)&object->position);
	ft_free_and_null((void **)&object->norm);
	ft_free_and_null((void **)&object->color);
	ft_free_and_null((void **)&object);
}
