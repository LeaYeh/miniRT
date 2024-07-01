/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hit_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:28:28 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/29 21:16:07 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"
#include "debug.h"

Test(hit, hit_sphere_outside_x)
{
	t_ray			ray;
	t_obj			sphere;
	t_hit_record	rec;

	ray = init_ray(vector(2.0, 0, 0), vector(-1, 0, 0));
	sphere = (t_obj){0};
	sphere = (t_obj){
		.type = SPHERE,
		.position = vector(0, 0, 0),
		.norm = vector(0, 1, 0),
		.color= vector(0, 255, 0),
		.diameter = 1.0};
	cr_assert_eq(hit_sphere(&ray, &sphere, &rec), true, "hit_sphere() detection incorrect");
	cr_assert_eq(rec.t, 1.0, "hit_sphere() t value incorrect");
	cr_assert_eq(rec.front_face, true, "hit_sphere() front_face value incorrect");
	cr_assert_eq(rec.point.x, 1.0, "hit_sphere() point.x value incorrect");
	cr_assert_eq(rec.point.y, 0.0, "hit_sphere() point.y value incorrect");
	cr_assert_eq(rec.point.z, 0.0, "hit_sphere() point.z value incorrect");
	cr_assert_eq(rec.norm.x, 1.0, "hit_sphere() norm.x value incorrect");
	cr_assert_eq(rec.norm.y, 0.0, "hit_sphere() norm.y value incorrect");
	cr_assert_eq(rec.norm.z, 0.0, "hit_sphere() norm.z value incorrect");
	cr_assert_eq(rec.color.x, 0.0, "hit_sphere() color.x value incorrect");
	cr_assert_eq(rec.color.y, 255.0, "hit_sphere() color.y value incorrect");
	cr_assert_eq(rec.color.z, 0.0, "hit_sphere() color.z value incorrect");
}

Test(hit, hit_sphere_outside_y)
{
	t_ray			ray;
	t_obj			sphere;
	t_hit_record	rec;

	ray = init_ray(vector(0, 2.0, 0), vector(0, -1, 0));
	sphere = (t_obj){0};
	sphere = (t_obj){
		.type = SPHERE,
		.position = vector(0, 0, 0),
		.norm = vector(0, 1, 0),
		.color= vector(0, 255, 0),
		.diameter = 1.0};
	cr_assert_eq(hit_sphere(&ray, &sphere, &rec), true, "hit_sphere() detection incorrect");
	cr_assert_eq(rec.t, 1.0, "hit_sphere() t value incorrect");
	cr_assert_eq(rec.front_face, true, "hit_sphere() front_face value incorrect");
	cr_assert_eq(rec.point.x, 0.0, "hit_sphere() point.x value incorrect");
	cr_assert_eq(rec.point.y, 1.0, "hit_sphere() point.y value incorrect");
	cr_assert_eq(rec.point.z, 0.0, "hit_sphere() point.z value incorrect");
	cr_assert_eq(rec.norm.x, 0.0, "hit_sphere() norm.x value incorrect");
	cr_assert_eq(rec.norm.y, 1.0, "hit_sphere() norm.y value incorrect");
	cr_assert_eq(rec.norm.z, 0.0, "hit_sphere() norm.z value incorrect");
	cr_assert_eq(rec.color.x, 0.0, "hit_sphere() color.x value incorrect");
	cr_assert_eq(rec.color.y, 255.0, "hit_sphere() color.y value incorrect");
	cr_assert_eq(rec.color.z, 0.0, "hit_sphere() color.z value incorrect");
}

Test(hit, hit_sphere_outside_z)
{
	t_ray			ray;
	t_obj			sphere;
	t_hit_record	rec;

	ray = init_ray(vector(0, 0, 2.0), vector(0, 0, -1));
	sphere = (t_obj){0};
	sphere = (t_obj){
		.type = SPHERE,
		.position = vector(0, 0, 0),
		.norm = vector(0, 1, 0),
		.color= vector(0, 255, 0),
		.diameter = 1.0};
	cr_assert_eq(hit_sphere(&ray, &sphere, &rec), true, "hit_sphere() detection incorrect");
	cr_assert_eq(rec.t, 1.0, "hit_sphere() t value incorrect");
	cr_assert_eq(rec.front_face, true, "hit_sphere() front_face value incorrect");
	cr_assert_eq(rec.point.x, 0.0, "hit_sphere() point.x value incorrect");
	cr_assert_eq(rec.point.y, 0.0, "hit_sphere() point.y value incorrect");
	cr_assert_eq(rec.point.z, 1.0, "hit_sphere() point.z value incorrect");
	cr_assert_eq(rec.norm.x, 0.0, "hit_sphere() norm.x value incorrect");
	cr_assert_eq(rec.norm.y, 0.0, "hit_sphere() norm.y value incorrect");
	cr_assert_eq(rec.norm.z, 1.0, "hit_sphere() norm.z value incorrect");
	cr_assert_eq(rec.color.x, 0.0, "hit_sphere() color.x value incorrect");
	cr_assert_eq(rec.color.y, 255.0, "hit_sphere() color.y value incorrect");
	cr_assert_eq(rec.color.z, 0.0, "hit_sphere() color.z value incorrect");
}

Test(hit, hit_sphere_inside)
{
	t_ray			ray;
	t_obj			sphere;
	t_hit_record	rec;

	ray = init_ray(vector(0, 0, 5), vector(0, 0, 1));
	sphere = (t_obj){0};
	sphere = (t_obj){
		.type = SPHERE,
		.position = vector(0, 0, 0),
		.norm = vector(0, 1, 0),
		.color= vector(0, 255, 0),
		.diameter = 10.0};
	cr_assert_eq(hit_sphere(&ray, &sphere, &rec), true, "hit_sphere() detection incorrect");
	cr_assert_eq(rec.t, 5.0, "hit_sphere() t value incorrect");
	cr_assert_eq(rec.front_face, false, "hit_sphere() front_face value incorrect");
	cr_assert_eq(rec.point.x, 0.0, "hit_sphere() point.x value incorrect");
	cr_assert_eq(rec.point.y, 0.0, "hit_sphere() point.y value incorrect");
	cr_assert_eq(rec.point.z, 10.0, "hit_sphere() point.z value incorrect");
	cr_assert_eq(rec.norm.x, 0.0, "hit_sphere() norm.x value incorrect");
	cr_assert_eq(rec.norm.y, 0.0, "hit_sphere() norm.y value incorrect");
	cr_assert_eq(rec.norm.z, -1.0, "hit_sphere() norm.z value incorrect");
	cr_assert_eq(rec.color.x, 0.0, "hit_sphere() color.x value incorrect");
	cr_assert_eq(rec.color.y, 255.0, "hit_sphere() color.y value incorrect");
	cr_assert_eq(rec.color.z, 0.0, "hit_sphere() color.z value incorrect");
}

Test(hit, hit_sphere_miss)
{
	t_ray			ray;
	t_obj			sphere;
	t_hit_record	rec;

	ray = init_ray(vector(2.0, 0, 0), vector(1, 0, 0));
	sphere = (t_obj){0};
	sphere = (t_obj){
		.type = SPHERE,
		.position = vector(0, 0, 0),
		.norm = vector(0, 1, 0),
		.color= vector(0, 255, 0),
		.diameter = 1.0};
	cr_assert_eq(hit_sphere(&ray, &sphere, &rec), false, "hit_sphere() detection incorrect");
}
