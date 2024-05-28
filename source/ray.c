/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:57:25 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/26 14:58:59 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	*create_ray(t_vec3 *origin, t_vec3 *direction)
{
    t_ray	*r;

    r = (t_ray *)calloc(1, sizeof(t_ray));
    if (!r)
        return (NULL);
    r->origin = origin;
    r->direction = direction;
    r->point_at_parameter = NULL;
    return (r);
}
