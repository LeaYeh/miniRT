/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:57:56 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/26 18:13:21 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_PRIVATE_H
# define READER_PRIVATE_H

# include "reader.h"
# include "utils.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>

bool	is_valid_filename(char *filename);
bool	is_valid_float(char *str);
bool	is_valid_vector(char *str);

bool	parse_environment(t_scene *scene, char *id);
bool	parse_object(t_scene *scene, char *id);
bool	parse_vector(t_vec3 *v, char *str);
bool	parse_unit_vector(t_vec3 *v, char *str);
bool	parse_color_vector(t_vec3 *v, char *str);

#endif
