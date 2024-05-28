/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:57:56 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/28 15:14:55 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef READER_PRIVATE_H
# define READER_PRIVATE_H

# include <fcntl.h>
# include <unistd.h>
# include "reader.h"
# include "utils.h"

bool	is_valid_filename(char *filename);

bool	parse_object(t_scene *scene, char **tokens);
bool	parse_environment(t_scene *scene, char **tokens);

void	free_scene(t_scene **scene);
void	free_object_array(t_obj ***objects);

#endif
