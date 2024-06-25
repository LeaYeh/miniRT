/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 22:25:03 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/25 20:08:14 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

void	translate(t_vec3 *v, t_vec3 translation)
{
	v->x = v->x + translation.x;
	v->y = v->y + translation.y;
	v->z = v->z + translation.z;
}
