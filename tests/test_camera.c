/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:58:00 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/14 20:31:06 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

Test(camera, camera_utils_degree_to_radian)
{
	cr_assert_float_eq(degree_to_radian(90), 1.57079632679, 0.001,
		"90 degrees is not equal to 1.57079632679 radians");
	cr_assert_float_eq(degree_to_radian(180), 3.14159265359, 0.001,
		"180 degrees is not equal to 3.14159265359 radians");
	cr_assert_float_eq(degree_to_radian(270), 4.71238898038, 0.001,
		"270 degrees is not equal to 4.71238898038 radians");
	cr_assert_float_eq(degree_to_radian(360), 6.28318530718, 0.001,
		"360 degrees is not equal to 6.28318530718 radians");
}

Test(camera, camera_init)
{
	t_camera	cam;

	cam = (t_camera){.position = (t_vec3){.x = -50, .y = 0, .z = 20},
		.norm = (t_vec3){.x = 0, .y = 0, .z = 1},
		.fov = 70};

	if (!init_camera(&cam))
		cr_assert_fail("Camera initialization failed");
	cr_assert_float_eq(cam.theta, 1.221730, 0.001, "Theta is not correct");

	cr_assert_float_eq(cam.viewport.width, 2.490066, 0.001, "Viewport width is not correct");
	cr_assert_float_eq(cam.viewport.height, 1.400414, 0.001, "Viewport height is not correct");

	cr_assert_float_eq(cam.viewport.origin_corner.x, -51.245033, 0.001,
		"Origin corner x is not correct");
	cr_assert_float_eq(cam.viewport.origin_corner.y, -0.700207, 0.001,
		"Origin corner y is not correct");
	cr_assert_float_eq(cam.viewport.origin_corner.z, 19.0, 0.001,
		"Origin corner z is not correct");

	cr_assert_float_eq(cam.viewport.v.x, 0.0, 0.001, "V x is not correct");
	cr_assert_float_eq(cam.viewport.v.y, 1.0, 0.001, "V y is not correct");
	cr_assert_float_eq(cam.viewport.v.z, 0.0, 0.001, "V z is not correct");

	cr_assert_float_eq(cam.viewport.u.x, -1.0, 0.001, "U x is not correct");
	cr_assert_float_eq(cam.viewport.u.y, 0.0, 0.001, "U y is not correct");
	cr_assert_float_eq(cam.viewport.u.z, 0.0, 0.001, "U z is not correct");

	cr_assert_float_eq(cam.viewport.w.x, 0.0, 0.001, "W x is not correct");
	cr_assert_float_eq(cam.viewport.w.y, 0.0, 0.001, "W y is not correct");
	cr_assert_float_eq(cam.viewport.w.z, -1.0, 0.001, "W z is not correct");

	// cr_assert_float_eq(cam.pixel.delta_u.x, 0.00277777777, 0.001,
	// 	"Delta u x is not correct");
	// cr_assert_float_eq(cam.pixel.delta_u.y, 0.0, 0.001, "Delta u y is not correct");
	// cr_assert_float_eq(cam.pixel.delta_u.z, 0.0, 0.001, "Delta u z is not correct");
	// cr_assert_float_eq(cam.pixel.delta_v.x, 0.0, 0.001, "Delta v x is not correct");
	// cr_assert_float_eq(cam.pixel.delta_v.y, 0.00277777777, 0.001,
	// 	"Delta v y is not correct");
	// cr_assert_float_eq(cam.pixel.delta_v.z, 0.0, 0.001, "Delta v z is not correct");
	// cr_assert_eq(ft_lstsize(cam.ray_list), WINDOW_WIDTH * WINDOW_HEIGHT,
	// 	"Ray list size is not correct");
}
