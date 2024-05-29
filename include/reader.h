/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:52:01 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/29 19:26:18 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include "defines.h"
# include "get_next_line.h"

t_scene	*read_scene(char *filename);
void	free_scene(t_scene **scene);

#endif
