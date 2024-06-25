/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:54:35 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/25 14:54:37 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_PRIVATE_H
# define TRANSFORM_PRIVATE_H

# include "vec3.h"

void	rotate(t_vec3 *v, t_vec3 rotation);
void	translate(t_vec3 *v, t_vec3 translation);

#endif
