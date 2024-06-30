/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:41:00 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/29 20:10:15 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include "libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <math.h>

/* Error Codes */
# define SUCCESS				0
# define ERR_ARGC				1
# define ERR_INIT				2

/* Error Messages */
# define INVALID_FILE_FMT		"Invalid file format."
# define INVALID_IDENTIFIER		"Invalid identifier."
# define INVALID_NUM_ARG		"Invalid number of arguments."
# define INVALID_AMB_FMT		"Invalid ambient light format."
# define INVALID_CAM_FMT		"Invalid camera format."
# define INVALID_LIG_FMT		"Invalid light format."
# define INVALID_SPH_FMT		"Invalid sphere format."
# define INVALID_PLA_FMT		"Invalid plane format."
# define INVALID_CYL_FMT		"Invalid cylinder format."
# define MULTIPLE_UNIQ_ID		"Multiple unique identifiers."
# define EMPTY_SCENE			"Empty scene."
# define FAILED_OPEN_FILE		"Failed to open file."
# define FAILED_READ_FILE		"Failed to read file."
# define FAILED_CLOSE_FILE		"Failed to close file."
# define FAILED_ALLOC_MEM		"Failed to allocate memory."

# define WINDOW_WIDTH			640
# define WINDOW_HEIGHT			360
# define HORIZONTAL_UNIT		1
# define VERTICAL_UNIT			1

# define MAX_DEPTH				1

# define INTERVAL_TRANSLATE		0.5
# define INTERVAL_ROTATE		0.5
# define INTERVAL_SCALE			0.5
# define INTERVAL_FOV			1
# define INTERVAL_BRIGHTNESS	0.1
# define FACTOR_FAST			10

#endif
