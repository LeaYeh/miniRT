/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hit_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:28:28 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/17 16:07:18 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"
#include "debug.h"

Test(hit, hit_sphere_outside)
{
	const t_vec3	vec3 = {.ops = init_ops()};
	t_ray			ray;
	t_obj			shpere;
	t_hit_record	rec;

	ray = (t_ray){
		.origin = (t_vec3){.x = 0, .y = 2.0, .z = 0},
		.direction = (t_vec3){.x = 0, .y = -1, .z = 0}};
	shpere = (t_obj){
		.position = (t_vec3){.x = 0, .y = 0, .z = 0},
		.norm = (t_vec3){.x = 0, .y = 1, .z = 0},
		.d_param1 = 1.0};
	cr_assert_eq(hit_sphere(vec3, &ray, &shpere, &rec), true, "hit_sphere() detection incorrect");
	cr_assert_eq(rec.t, 1.0, "hit_sphere() t value incorrect");
	cr_assert_eq(rec.front_face, true, "hit_sphere() front_face value incorrect");
	cr_assert_eq(rec.point.x, 0.0, "hit_sphere() point.x value incorrect");
	cr_assert_eq(rec.point.y, 1.0, "hit_sphere() point.y value incorrect");
	cr_assert_eq(rec.point.z, 0.0, "hit_sphere() point.z value incorrect");
	cr_assert_eq(rec.norm.x, 0.0, "hit_sphere() norm.x value incorrect");
	cr_assert_eq(rec.norm.y, 1.0, "hit_sphere() norm.y value incorrect");
	cr_assert_eq(rec.norm.z, 0.0, "hit_sphere() norm.z value incorrect");
}

Test(hit, hit_sphere_inside)
{
	const t_vec3	vec3 = {.ops = init_ops()};
	t_ray			ray;
	t_obj			shpere;
	t_hit_record	rec;

	ray = (t_ray){
		.origin = (t_vec3){.x = 0, .y = 0, .z = 5},
		.direction = (t_vec3){.x = 0, .y = 0, .z = 1}};
	shpere = (t_obj){
		.position = (t_vec3){.x = 0, .y = 0, .z = 0},
		.norm = (t_vec3){.x = 0, .y = 1, .z = 0},
		.d_param1 = 10.0};
	cr_assert_eq(hit_sphere(vec3, &ray, &shpere, &rec), true, "hit_sphere() detection incorrect");
	cr_assert_eq(rec.t, 5.0, "hit_sphere() t value incorrect");
	cr_assert_eq(rec.front_face, false, "hit_sphere() front_face value incorrect");
	cr_assert_eq(rec.point.x, 0.0, "hit_sphere() point.x value incorrect");
	cr_assert_eq(rec.point.y, 0.0, "hit_sphere() point.y value incorrect");
	cr_assert_eq(rec.point.z, 10.0, "hit_sphere() point.z value incorrect");
	cr_assert_eq(rec.norm.x, 0.0, "hit_sphere() norm.x value incorrect");
	cr_assert_eq(rec.norm.y, -1.0, "hit_sphere() norm.y value incorrect");
	cr_assert_eq(rec.norm.z, 0.0, "hit_sphere() norm.z value incorrect");
}

Test(hit, hit_sphere_miss)
{
	const t_vec3	vec3 = {.ops = init_ops()};
	t_ray			ray;
	t_obj			shpere;
	t_hit_record	rec;

	ray = (t_ray){
		.origin = (t_vec3){.x = 2.0, .y = 0, .z = 0},
		.direction = (t_vec3){.x = 1, .y = 0, .z = 0}};
	shpere = (t_obj){
		.position = (t_vec3){.x = 0, .y = 0, .z = 0},
		.norm = (t_vec3){.x = 0, .y = 1, .z = 0},
		.d_param1 = 1.0};
	cr_assert_eq(hit_sphere(vec3, &ray, &shpere, &rec), false, "hit_sphere() detection incorrect");
}
