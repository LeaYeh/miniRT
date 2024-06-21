/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_render_ambient.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:55:43 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/21 15:42:59 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"
#include "debug.h"

Test(render, ambient)
{
	t_hit_record	rec;
	t_amblight		ambient_light;

	rec = (t_hit_record){0};
	rec = (t_hit_record){
		.shoot_direction = vector(1, 1, 0),
		.point = vector(0, 0, 0),
		.norm = vector(1, 0, 0),
		.color = vector(1, 0, 0),
		.front_face = true,
		.t = 1.0
	};
	ambient_light = (t_amblight){0};
	ambient_light = (t_amblight){
		.color = vector(1, 1, 1),
		.ratio = 0.5
	};
	cr_assert_eq(ambient(&rec, &ambient_light).x, 0.5, "ambient() color.x value incorrect");
	cr_assert_eq(ambient(&rec, &ambient_light).y, 0.0, "ambient() color.y value incorrect");
	cr_assert_eq(ambient(&rec, &ambient_light).z, 0.0, "ambient() color.z value incorrect");
}
