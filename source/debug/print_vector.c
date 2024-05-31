/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:37:11 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/29 20:38:16 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_vector(t_vec3 *vec)
{
	if (!vec)
	{
		printf("NULL\n");
		return ;
	}
	printf("(%f, %f, %f)\n", vec->x, vec->y, vec->z);
}