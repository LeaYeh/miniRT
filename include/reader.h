/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:52:01 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/30 20:16:15 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include "defines.h"
# include "scene.h"
# include "object.h"
# include "get_next_line.h"

t_scene	*read_scene(char *filename);
void	free_scene(t_scene **scene);

#endif
