/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hit_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:27:23 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/17 18:09:22 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"
#include "debug.h"

Test(hit, hit_plane_under)
{
	const t_vec3	vec3 = {.ops = init_ops()};
	t_ray			ray;
	t_obj			plane;
	t_hit_record	rec;

	ray = (t_ray){
		.origin = (t_vec3){.x = 0, .y = -1.0, .z = 0},
		.direction = (t_vec3){.x = 0, .y = 1, .z = 0}};
	plane = (t_obj){
		.type = PLANE,
		.position = (t_vec3){.x = 0, .y = 0, .z = 0},
		.norm = (t_vec3){.x = 0, .y = 1, .z = 0}};
	cr_assert_eq(hit_plane(vec3, &ray, &plane, &rec), true, "hit_plane() detection incorrect");
	cr_assert_eq(rec.t, 1.0, "hit_plane() t value incorrect");
	cr_assert_eq(rec.front_face, false, "hit_plane() front_face value incorrect");
	cr_assert_eq(rec.point.x, 0.0, "hit_plane() point.x value incorrect");
	cr_assert_eq(rec.point.y, 0.0, "hit_plane() point.y value incorrect");
	cr_assert_eq(rec.point.z, 0.0, "hit_plane() point.z value incorrect");
	cr_assert_eq(rec.norm.x, 0.0, "hit_plane() norm.x value incorrect");
	cr_assert_eq(rec.norm.y, -1.0, "hit_plane() norm.y value incorrect");
	cr_assert_eq(rec.norm.z, 0.0, "hit_plane() norm.z value incorrect");
}

Test(hit, hit_plane_above)
{
	const t_vec3	vec3 = {.ops = init_ops()};
	t_ray			ray;
	t_obj			plane;
	t_hit_record	rec;

	ray = (t_ray){
		.origin = (t_vec3){.x = 0, .y = 2.0, .z = 0},
		.direction = (t_vec3){.x = 0, .y = -1, .z = 0}};
	plane = (t_obj){
		.type = PLANE,
		.position = (t_vec3){.x = 0, .y = 0, .z = 0},
		.norm = (t_vec3){.x = 0, .y = 1, .z = 0}};
	cr_assert_eq(hit_plane(vec3, &ray, &plane, &rec), true, "hit_plane() detection incorrect");
	cr_assert_eq(rec.t, 2.0, "hit_plane() t value incorrect");
	cr_assert_eq(rec.front_face, true, "hit_plane() front_face value incorrect");
	cr_assert_eq(rec.point.x, 0.0, "hit_plane() point.x value incorrect");
	cr_assert_eq(rec.point.y, 0.0, "hit_plane() point.y value incorrect");
	cr_assert_eq(rec.point.z, 0.0, "hit_plane() point.z value incorrect");
	cr_assert_eq(rec.norm.x, 0.0, "hit_plane() norm.x value incorrect");
	cr_assert_eq(rec.norm.y, 1.0, "hit_plane() norm.y value incorrect");
	cr_assert_eq(rec.norm.z, 0.0, "hit_plane() norm.z value incorrect");
}

Test(hit, hit_plane_miss)
{
	const t_vec3	vec3 = {.ops = init_ops()};
	t_ray			ray;
	t_obj			plane;
	t_hit_record	rec;

	ray = (t_ray){
		.origin = (t_vec3){.x = 0, .y = 1.0, .z = 0},
		.direction = (t_vec3){.x = 0, .y = 1, .z = 0}};
	plane = (t_obj){
		.type = PLANE,
		.position = (t_vec3){.x = 0, .y = 0, .z = 0},
		.norm = (t_vec3){.x = 0, .y = 1, .z = 0}};
	cr_assert_eq(hit_plane(vec3, &ray, &plane, &rec), false, "hit_plane() detection incorrect");
}
