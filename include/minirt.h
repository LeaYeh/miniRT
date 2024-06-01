/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:18:37 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/01 11:32:30 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "reader.h"
# include "environment.h"

typedef struct s_minirt
{
	t_scene	*scene;
}	t_minirt;

bool	init_minirt(t_minirt *minirt, char *filename);
bool	free_minirt(t_minirt *minirt);

#endif
