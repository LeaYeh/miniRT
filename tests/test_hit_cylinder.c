/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hit_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:30:12 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/29 21:16:25 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"
#include "debug.h"

Test(hit, hit_cylinder_miss)
{
	const t_vec3	vec3 = {.ops = init_ops()};
	t_ray			ray;
	t_obj			cylinder;
	t_hit_record	rec;

	ray = init_ray(vector(0, 5.0, 0), vector(1, 0, 0));
	cylinder =(t_obj){0};
	cylinder = (t_obj){
		.type = CYLINDER,
		.position = vector(0, 0, 0),
		.norm = vector(0, 1, 0),
		.diameter = 1.0,
		.height = 5.0};
	cr_assert_eq(hit_cylinder(vec3, &ray, &cylinder, &rec), false, "hit_cylinder() detection incorrect");
}

Test(hit, hit_cylinder_outside_side_x)
{
	const t_vec3	vec3 = {.ops = init_ops()};
	t_ray			ray;
	t_obj			cylinder;
	t_hit_record	rec;

	ray = init_ray(vector(2.0, 2.0, 0), vector(-1, 0, 0));
	cylinder =(t_obj){0};
	cylinder = (t_obj){
		.type = CYLINDER,
		.position = vector(0, 0, 0),
		.norm = vector(0, 1, 0),
		.diameter = 1.0,
		.height = 5.0};
	cr_assert_eq(hit_cylinder(vec3, &ray, &cylinder, &rec), true, "hit_cylinder() detection incorrect");
	cr_assert_eq(rec.t, 1.0, "hit_cylinder() t value incorrect");
	cr_assert_eq(rec.front_face, true, "hit_cylinder() front_face value incorrect");
	cr_assert_eq(rec.point.x, 1.0, "hit_cylinder() point.x value incorrect");
	cr_assert_eq(rec.point.y, 2.0, "hit_cylinder() point.y value incorrect");
	cr_assert_eq(rec.point.z, 0.0, "hit_cylinder() point.z value incorrect");
	cr_assert_eq(rec.norm.x, 1.0, "hit_cylinder() norm.x value incorrect");
	cr_assert_eq(rec.norm.y, 0.0, "hit_cylinder() norm.y value incorrect");
	cr_assert_eq(rec.norm.z, 0.0, "hit_cylinder() norm.z value incorrect");
}

// Test(hit, hit_cylinder_outside_side_z)
// {
// 	const t_vec3	vec3 = {.ops = init_ops()};
// 	t_ray			ray;
// 	t_obj			cylinder;
// 	t_hit_record	rec;

// 	ray = (t_ray){
// 		.origin = (t_vec3){.x = 0.0, .y = 2.0, .z = 2.0},
// 		.direction = (t_vec3){.x = 0, .y = 0, .z = -1}};
// 	cylinder = (t_obj){
// 		.type = CYLINDER,
// 		.position = (t_vec3){.x = 0, .y = 0, .z = 0},
// 		.norm = (t_vec3){.x = 0, .y = 1, .z = 0},
// 		.diameter = 1.0,
// 		.height = 5.0};
// 	cr_assert_eq(hit_cylinder(vec3, &ray, &cylinder, &rec), true, "hit_cylinder() detection incorrect");
// 	cr_assert_eq(rec.t, 1.0, "hit_cylinder() t value incorrect");
// 	cr_assert_eq(rec.front_face, true, "hit_cylinder() front_face value incorrect");
// 	cr_assert_eq(rec.point.x, 0.0, "hit_cylinder() point.x value incorrect");
// 	cr_assert_eq(rec.point.y, 2.0, "hit_cylinder() point.y value incorrect");
// 	cr_assert_eq(rec.point.z, 1.0, "hit_cylinder() point.z value incorrect");
// 	cr_assert_eq(rec.norm.x, 0.0, "hit_cylinder() norm.x value incorrect");
// 	cr_assert_eq(rec.norm.y, 0.0, "hit_cylinder() norm.y value incorrect");
// 	cr_assert_eq(rec.norm.z, 1.0, "hit_cylinder() norm.z value incorrect");

// }

// Test(hit, hit_cylinder_inside_side_x)
// {
// 	const t_vec3	vec3 = {.ops = init_ops()};
// 	t_ray			ray;
// 	t_obj			cylinder;
// 	t_hit_record	rec;

// 	ray = (t_ray){
// 		.origin = (t_vec3){.x = 0.0, 0.0, .z = 0},
// 		.direction = (t_vec3){.x = 1, .y = 0, .z = 0}};
// 	cylinder = (t_obj){
// 		.type = CYLINDER,
// 		.position = (t_vec3){.x = 0, .y = 0, .z = 0},
// 		.norm = (t_vec3){.x = 0, .y = 1, .z = 0},
// 		.diameter = 1.0,
// 		.height = 5.0};
// 	cr_assert_eq(hit_cylinder(vec3, &ray, &cylinder, &rec), true, "hit_cylinder() detection incorrect");
// 	cr_assert_eq(rec.t, 1.0, "hit_cylinder() t value incorrect");
// 	cr_assert_eq(rec.front_face, false, "hit_cylinder() front_face value incorrect");
// 	cr_assert_eq(rec.point.x, 1.0, "hit_cylinder() point.x value incorrect");
// 	cr_assert_eq(rec.point.y, 0.0, "hit_cylinder() point.y value incorrect");
// 	cr_assert_eq(rec.point.z, 0.0, "hit_cylinder() point.z value incorrect");
// 	cr_assert_eq(rec.norm.x, -1.0, "hit_cylinder() norm.x value incorrect");
// 	cr_assert_eq(rec.norm.y, 0.0, "hit_cylinder() norm.y value incorrect");
// 	cr_assert_eq(rec.norm.z, 0.0, "hit_cylinder() norm.z value incorrect");
// }

// Test(hit, hit_cylinder_inside_side_z)
// {
// 	const t_vec3	vec3 = {.ops = init_ops()};
// 	t_ray			ray;
// 	t_obj			cylinder;
// 	t_hit_record	rec;

// 	ray = (t_ray){
// 		.origin = (t_vec3){.x = 0.0, 0.0, .z = 0},
// 		.direction = (t_vec3){.x = 0, .y = 0, .z = 1}};
// 	cylinder = (t_obj){
// 		.type = CYLINDER,
// 		.position = (t_vec3){.x = 0, .y = 0, .z = 0},
// 		.norm = (t_vec3){.x = 0, .y = 1, .z = 0},
// 		.diameter = 1.0,
// 		.height = 5.0};
// 	cr_assert_eq(hit_cylinder(vec3, &ray, &cylinder, &rec), true, "hit_cylinder() detection incorrect");
// 	cr_assert_eq(rec.t, 1.0, "hit_cylinder() t value incorrect");
// 	cr_assert_eq(rec.front_face, false, "hit_cylinder() front_face value incorrect");
// 	cr_assert_eq(rec.point.x, 0.0, "hit_cylinder() point.x value incorrect");
// 	cr_assert_eq(rec.point.y, 0.0, "hit_cylinder() point.y value incorrect");
// 	cr_assert_eq(rec.point.z, 1.0, "hit_cylinder() point.z value incorrect");
// 	cr_assert_eq(rec.norm.x, 0.0, "hit_cylinder() norm.x value incorrect");
// 	cr_assert_eq(rec.norm.y, 0.0, "hit_cylinder() norm.y value incorrect");
// 	cr_assert_eq(rec.norm.z, -1.0, "hit_cylinder() norm.z value incorrect");
// }

Test(hit, hit_cylinder_outside_top)
{
	const t_vec3	vec3 = {.ops = init_ops()};
	t_ray			ray;
	t_obj			cylinder;
	t_hit_record	rec;

	ray = init_ray(vector(0.0, 20.0, 0), vector(0, -1, 0));
	cylinder =(t_obj){0};
	cylinder = (t_obj){
		.type = CYLINDER,
		.position = vector(0, 0, 0),
		.norm = vector(0, 1, 0),
		.color = vector(0, 255, 0),
		.diameter = 1.0,
		.height = 5.0};
	cr_assert_eq(hit_cylinder(vec3, &ray, &cylinder, &rec), true, "hit_cylinder() detection incorrect");
	cr_assert_eq(rec.t, 17.5, "hit_cylinder() t value incorrect");
	cr_assert_eq(rec.front_face, true, "hit_cylinder() front_face value incorrect");
	cr_assert_eq(rec.point.x, 0.0, "hit_cylinder() point.x value incorrect");
	cr_assert_eq(rec.point.y, 2.5, "hit_cylinder() point.y value incorrect");
	cr_assert_eq(rec.point.z, 0.0, "hit_cylinder() point.z value incorrect");
	cr_assert_eq(rec.norm.x, 0.0, "hit_cylinder() norm.x value incorrect");
	cr_assert_eq(rec.norm.y, 1.0, "hit_cylinder() norm.y value incorrect");
	cr_assert_eq(rec.norm.z, 0.0, "hit_cylinder() norm.z value incorrect");
	cr_assert_eq(rec.color.x, 0.0, "hit_cylinder() color.x value incorrect");
	cr_assert_eq(rec.color.y, 255.0, "hit_cylinder() color.y value incorrect");
	cr_assert_eq(rec.color.z, 0.0, "hit_cylinder() color.z value incorrect");
}

Test(hit, hit_cylinder_inside_top)
{
	const t_vec3	vec3 = {.ops = init_ops()};
	t_ray			ray;
	t_obj			cylinder;
	t_hit_record	rec;

	ray = init_ray(vector(0.0, 0.0, 0), vector(0, 1, 0));
	cylinder =(t_obj){0};
	cylinder = (t_obj){
		.type = CYLINDER,
		.position = vector(0, 0, 0),
		.norm = vector(0, 1, 0),
		.color = vector(0, 0, 0),
		.diameter = 1.0,
		.height = 5.0};
	printf("hit: %d\n", hit_cylinder(vec3, &ray, &cylinder, &rec));
	print_hit_record(&rec);
	cr_assert_eq(hit_cylinder(vec3, &ray, &cylinder, &rec), true, "hit_cylinder() detection incorrect");
	cr_assert_eq(rec.t, 2.5, "hit_cylinder() t value incorrect");
	cr_assert_eq(rec.front_face, false, "hit_cylinder() front_face value incorrect");
	cr_assert_eq(rec.point.x, 0.0, "hit_cylinder() point.x value incorrect");
	cr_assert_eq(rec.point.y, 2.5, "hit_cylinder() point.y value incorrect");
	cr_assert_eq(rec.point.z, 0.0, "hit_cylinder() point.z value incorrect");
	cr_assert_eq(rec.norm.x, 0.0, "hit_cylinder() norm.x value incorrect");
	cr_assert_eq(rec.norm.y, -1.0, "hit_cylinder() norm.y value incorrect");
	cr_assert_eq(rec.norm.z, 0.0, "hit_cylinder() norm.z value incorrect");
	cr_assert_eq(rec.color.x, 0.0, "hit_cylinder() color.x value incorrect");
	cr_assert_eq(rec.color.y, 255.0, "hit_cylinder() color.y value incorrect");
	cr_assert_eq(rec.color.z, 0.0, "hit_cylinder() color.z value incorrect");
}

Test(hit, hit_cylinder_outside_bottom)
{
	const t_vec3	vec3 = {.ops = init_ops()};
	t_ray			ray;
	t_obj			cylinder;
	t_hit_record	rec;

	ray = init_ray(vector(0.0, -20.0, 0), vector(0, 1, 0));
	cylinder =(t_obj){0};
	cylinder = (t_obj){
		.type = CYLINDER,
		.position = vector(0, 0, 0),
		.norm = vector(0, 1, 0),
		.color = vector(0, 255, 0),
		.diameter = 1.0,
		.height = 5.0};
	cr_assert_eq(hit_cylinder(vec3, &ray, &cylinder, &rec), true, "hit_cylinder() detection incorrect");
	cr_assert_eq(rec.t, 17.5, "hit_cylinder() t value incorrect");
	cr_assert_eq(rec.front_face, true, "hit_cylinder() front_face value incorrect");
	cr_assert_eq(rec.point.x, 0.0, "hit_cylinder() point.x value incorrect");
	cr_assert_eq(rec.point.y, -2.5, "hit_cylinder() point.y value incorrect");
	cr_assert_eq(rec.point.z, 0.0, "hit_cylinder() point.z value incorrect");
	cr_assert_eq(rec.norm.x, 0.0, "hit_cylinder() norm.x value incorrect");
	cr_assert_eq(rec.norm.y, -1.0, "hit_cylinder() norm.y value incorrect");
	cr_assert_eq(rec.norm.z, 0.0, "hit_cylinder() norm.z value incorrect");
	cr_assert_eq(rec.color.x, 0.0, "hit_cylinder() color.x value incorrect");
	cr_assert_eq(rec.color.y, 255.0, "hit_cylinder() color.y value incorrect");
	cr_assert_eq(rec.color.z, 0.0, "hit_cylinder() color.z value incorrect");
}

Test(hit, hit_cylinder_inside_bottom)
{
	const t_vec3	vec3 = {.ops = init_ops()};
	t_ray			ray;
	t_obj			cylinder;
	t_hit_record	rec;

	ray = init_ray(vector(0.0, 0.0, 0), vector(0, -1, 0));
	cylinder =(t_obj){0};
	cylinder = (t_obj){
		.type = CYLINDER,
		.position = vector(0, 0, 0),
		.norm = vector(0, 1, 0),
		.color = vector(0, 0, 0),
		.diameter = 1.0,
		.height = 5.0};
	cr_assert_eq(hit_cylinder(vec3, &ray, &cylinder, &rec), true, "hit_cylinder() detection incorrect");
	cr_assert_eq(rec.t, 2.5, "hit_cylinder() t value incorrect");
	cr_assert_eq(rec.front_face, false, "hit_cylinder() front_face value incorrect");
	cr_assert_eq(rec.point.x, 0.0, "hit_cylinder() point.x value incorrect");
	cr_assert_eq(rec.point.y, -2.5, "hit_cylinder() point.y value incorrect");
	cr_assert_eq(rec.point.z, 0.0, "hit_cylinder() point.z value incorrect");
	cr_assert_eq(rec.norm.x, 0.0, "hit_cylinder() norm.x value incorrect");
	cr_assert_eq(rec.norm.y, 1.0, "hit_cylinder() norm.y value incorrect");
	cr_assert_eq(rec.norm.z, 0.0, "hit_cylinder() norm.z value incorrect");
	cr_assert_eq(rec.color.x, 0.0, "hit_cylinder() color.x value incorrect");
	cr_assert_eq(rec.color.y, 255.0, "hit_cylinder() color.y value incorrect");
	cr_assert_eq(rec.color.z, 0.0, "hit_cylinder() color.z value incorrect");
}

Test(hit, hit_cylinder_outside_edge)
{
	const t_vec3	vec3 = {.ops = init_ops()};
	t_ray			ray;
	t_obj			cylinder;
	t_hit_record	rec;

	ray = init_ray(vector(0.0, 0.0, 0), vector(1, 1, 0));
	cylinder =(t_obj){0};
	cylinder = (t_obj){
		.type = CYLINDER,
		.position = vector(0, 0, 0),
		.norm = vector(0, 1, 0),
		.diameter = 1.0,
		.height = 5.0};
	cr_assert_eq(hit_cylinder(vec3, &ray, &cylinder, &rec), true, "hit_cylinder() detection incorrect");
	cr_assert_eq(rec.t, 1.0, "hit_cylinder() t value incorrect");
	cr_assert_eq(rec.front_face, true, "hit_cylinder() front_face value incorrect");
	cr_assert_eq(rec.point.x, 1.0, "hit_cylinder() point.x value incorrect");
	cr_assert_eq(rec.point.y, 1.0, "hit_cylinder() point.y value incorrect");
	cr_assert_eq(rec.point.z, 0.0, "hit_cylinder() point.z value incorrect");
	// current logic is either hit side or top/bottom
	cr_assert_eq(rec.norm.x, 1.0, "hit_cylinder() norm.x value incorrect");
	cr_assert_eq(rec.norm.y, 0.0, "hit_cylinder() norm.y value incorrect");
	cr_assert_eq(rec.norm.z, 0.0, "hit_cylinder() norm.z value incorrect");
}
