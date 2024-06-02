/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:46:46 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/02 20:44:31 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_private.h"

void	free_scene(t_scene **scene)
{
	ft_lstclear(&(*scene)->camera.ray_list, free);
	ft_lstclear(&(*scene)->objects, free);
	ft_free_and_null((void **)scene);
}
