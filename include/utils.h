/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:46:03 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/30 19:26:57 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "ft_printf.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

double	degree_to_radian(double degrees);
void	free_array(char **array);
int		get_array_size(char **array);
void	print_error(char *reason);

#endif
