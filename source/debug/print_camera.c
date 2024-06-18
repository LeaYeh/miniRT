/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:49:52 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/18 15:58:16 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_camera_detail(t_camera camera)
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
	printf("\tTranslation: ");
	print_vector(camera.translation);
	printf("\tRotation: ");
	print_vector(camera.rotation);
	print_viewport(camera.viewport);
	print_pixel_grid(camera.pixel);
}

void	print_viewport(t_viewport viewport)
{
	printf("Viewport:\n");
	printf("\tOrigin Corner: ");
	print_vector(viewport.origin_corner);
	printf("\tV: ");
	print_vector(viewport.v);
	printf("\tU: ");
	print_vector(viewport.u);
	printf("\tW: ");
	print_vector(viewport.w);
	printf("\tWidth: %f\n", viewport.width);
	printf("\tHeight: %f\n", viewport.height);
}

void	print_pixel_grid(t_pixel_grid pixel)
{
	printf("Pixel Grid:\n");
	printf("\tPixel00: ");
	print_vector(pixel.pixel00);
	printf("\tDelta U: ");
	print_vector(pixel.delta_u);
	printf("\tDelta V: ");
	print_vector(pixel.delta_v);
	printf("\tWidth: %f\n", pixel.width);
	printf("\tHeight: %f\n", pixel.height);
}
