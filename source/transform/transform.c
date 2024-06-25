/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 22:21:07 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/25 20:08:14 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

void	transform(t_vec3 *position,
			t_vec3 *norm, t_vec3 rotation, t_vec3 translation)
{
	rotate(norm, rotation);
	translate(position, translation);
}
