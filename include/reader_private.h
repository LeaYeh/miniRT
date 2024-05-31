/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:57:56 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/31 16:40:16 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef READER_PRIVATE_H
# define READER_PRIVATE_H

# include <fcntl.h>
# include <unistd.h>
# include "reader.h"
# include "utils.h"

bool	is_valid_filename(char *filename);
bool	is_valid_number(char *str);
bool	is_valid_vector(char *str);

t_scene	*init_scene(void);

bool	parse_environment(t_scene *scene, char **tokens);
bool	parse_object(t_scene *scene, char **tokens);
bool	parse_vector(t_vec3 *v, char *str);

void	free_object(t_obj *object);
void	free_amblight(t_amblight **amblight);
void	free_camera(t_camera **camera);
void	free_light(t_light **light);

#endif
