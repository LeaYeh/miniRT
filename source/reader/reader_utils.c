/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:49:59 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/28 15:13:50 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "reader_private.h"

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
	free_object_array(&(*scene)->objects);
	free_amblight(&(*scene)->amblight);
	free_camera(&(*scene)->camera);
	free_light(&(*scene)->light);
	ft_free_and_null((void **)scene);
}
