/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:33:20 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/17 13:15:12 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "reader.h"
# include "vec3.h"
# include "hit.h"

void	print_vector(t_vec3 vec);
void	print_scene(t_scene *scene);
void	print_object(t_obj *object);
void	print_amblight(t_amblight amblight);
void	print_camera(t_camera camera);
void	print_camera_detail(t_camera camera);
void	print_pixel_grid(t_pixel_grid pixel);
void	print_light(t_light light);
void	print_hit_record_list(t_list *rec_list);
void	print_hit_record(t_hit_record *rec);

#endif
