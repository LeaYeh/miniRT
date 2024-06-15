/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:49:52 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/15 13:34:11 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void    print_camera_detail(t_camera camera)
{
    printf("Camera Detail:\n");
    printf("\tPosition: ");
    print_vector(camera.position);
    printf("\tNorm: ");
    print_vector(camera.norm);
    printf("\tFOV: %f\n", camera.fov);
    printf("\tTheta: %f\n", camera.theta);
    printf("\tFocal Length: %f\n", camera.focal_length);
    printf("\tAspect Ratio: %f\n", camera.aspect_ratio);
    printf("\tViewport:\n");
    printf("\t\tOrigin Corner: ");
    print_vector(camera.viewport.origin_corner);
    printf("\t\tV: ");
    print_vector(camera.viewport.v);
    printf("\t\tU: ");
    print_vector(camera.viewport.u);
    printf("\t\tW: ");
    print_vector(camera.viewport.w);
    printf("\t\tWidth: %f\n", camera.viewport.width);
    printf("\t\tHeight: %f\n", camera.viewport.height);
    printf("\tPixel Grid:\n");
    printf("\t\tOrigin Corner: ");
    print_vector(camera.pixel.origin_corner);
    printf("\t\tDelta U: ");
    print_vector(camera.pixel.delta_u);
    printf("\t\tDelta V: ");
    print_vector(camera.pixel.delta_v);
    printf("\tRay list size: %d\n", ft_lstsize(camera.ray_list));
}
