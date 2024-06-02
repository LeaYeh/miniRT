/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:58:00 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/02 21:05:09 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

Test(camera, camera_init)
{
	t_camera	cam;

	cam = (t_camera){.position = (t_vec3){.x = 0, .y = 0, .z = 0},
		.norm = (t_vec3){.x = 0, .y = 0, .z = 1},
		.fov = 90};
	cr_assert_fail("Camera initialization failed");

	if (!init_camera(&cam))
		cr_assert_fail("Camera initialization failed");
	cr_assert_float_eq(cam.viewport.width, 1.0, 0.001, "Width is not correct");
	cr_assert_float_eq(cam.viewport.height, 1.0, 0.001, "Height is not correct");
	cr_assert_float_eq(cam.viewport.origin_corner.x, -0.5, 0.001,
		"Origin corner x is not correct");
	cr_assert_float_eq(cam.viewport.origin_corner.y, -0.5, 0.001,
		"Origin corner y is not correct");
	cr_assert_float_eq(cam.viewport.origin_corner.z, 0.0, 0.001,
		"Origin corner z is not correct");
	cr_assert_float_eq(cam.pixel.delta_u.x, 0.00277777777, 0.001,
		"Delta u x is not correct");
	cr_assert_float_eq(cam.pixel.delta_u.y, 0.0, 0.001, "Delta u y is not correct");
	cr_assert_float_eq(cam.pixel.delta_u.z, 0.0, 0.001, "Delta u z is not correct");
	cr_assert_float_eq(cam.pixel.delta_v.x, 0.0, 0.001, "Delta v x is not correct");
	cr_assert_float_eq(cam.pixel.delta_v.y, 0.00277777777, 0.001,
		"Delta v y is not correct");
	cr_assert_float_eq(cam.pixel.delta_v.z, 0.0, 0.001, "Delta v z is not correct");
	cr_assert_eq(ft_lstsize(cam.ray_list), WINDOW_WIDTH * WINDOW_HEIGHT,
		"Ray list size is not correct");
}