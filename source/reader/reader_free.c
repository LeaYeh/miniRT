/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:46:46 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/29 21:19:08 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_private.h"

void	free_amblight(t_amblight **amblight)
{
	ft_free_and_null((void **)&(*amblight)->color);
	ft_free_and_null((void **)amblight);
}

void	free_camera(t_camera **camera)
{
	ft_free_and_null((void **)&(*camera)->position);
	ft_free_and_null((void **)&(*camera)->norm);
	ft_free_and_null((void **)camera);
}

void	free_light(t_light **light)
{
	ft_free_and_null((void **)&(*light)->position);
	ft_free_and_null((void **)&(*light)->color);
	ft_free_and_null((void **)light);
}

void	free_scene(t_scene **scene)
{
	ft_lstclear(&(*scene)->objects, (void (*)(void *))free_object);
	free_amblight(&(*scene)->amblight);
	free_camera(&(*scene)->camera);
	free_light(&(*scene)->light);
	ft_free_and_null((void **)scene);
}
