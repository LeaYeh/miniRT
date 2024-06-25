/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:54:31 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/25 20:07:57 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "vec3.h"

void	transform(t_vec3 *position,
			t_vec3 *norm, t_vec3 rotation, t_vec3 translation);
void	rotate(t_vec3 *v, t_vec3 rotation);
void	translate(t_vec3 *v, t_vec3 translation);

#endif
