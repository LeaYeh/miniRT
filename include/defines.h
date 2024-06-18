/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:41:00 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/01 15:04:51 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include "libft.h"

/* Error Codes */
# define SUCCESS			0
# define ERR_ARGC			1
# define ERR_INIT			2

# define SPHERE_ARG_NUM		3
# define PLANE_ARG_NUM		3
# define CYLINDER_ARG_NUM	5

# define INVALID_FILE			"invalid file format.\n"
# define INVALID_CONTENT_FMT	"invalid content format.\n"
# define FAILED_OPEN_FILE		"failed to open file.\n"
# define FAILED_ALLOC_MEM		"failed to allocate memory.\n"
# define INVALID_NUM_ARG		"invalid number of argument.\n"
# define INVALID_NUM_FMT		"invalid number format.\n"
# define FAILED_PARSE_VEC		"parse vector failed.\n"
# define INCORRECT_VIEWPORT		"incorrect viewport size.\n"

# define WINDOW_WIDTH		1600
# define WINDOW_HEIGHT		900
# define HORIZONTAL_UNIT	1
# define VERTICAL_UNIT		1

#endif
