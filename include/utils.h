/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:46:03 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/18 16:56:59 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

void	free_array(char **array);
int		get_array_size(char **array);
void	print_error(char *reason);

#endif
