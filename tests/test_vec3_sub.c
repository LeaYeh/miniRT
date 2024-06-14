/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec3_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:58:30 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/14 17:11:40 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

Test(vec3, vec3_sub_zero)
{
	t_vec3	vec3 = {.ops = init_ops()};
	t_vec3	v1 = {.x = 1.0, .y = 2.0, .z = 3.0};
	t_vec3	v2 = {.x = 0.0, .y = 0.0, .z = 0.0};
	t_vec3	result;

	result = vec3.ops->sub(v1, v2);
	cr_assert_float_eq(result.x, 1.0, 0.001, "X component is not correct");
	cr_assert_float_eq(result.y, 2.0, 0.001, "Y component is not correct");
	cr_assert_float_eq(result.z, 3.0, 0.001, "Z component is not correct");
}

Test(vec3, vec3_sub_negative)
{
	t_vec3	vec3 = {.ops = init_ops()};
	t_vec3	v1 = {.x = -1.0, .y = -2.0, .z = -3.0};
	t_vec3	v2 = {.x = -1.0, .y = -2.0, .z = -3.0};
	t_vec3	result;

	result = vec3.ops->sub(v1, v2);
	cr_assert_float_eq(result.x, 0.0, 0.001, "X component is not correct");
	cr_assert_float_eq(result.y, 0.0, 0.001, "Y component is not correct");
	cr_assert_float_eq(result.z, 0.0, 0.001, "Z component is not correct");
}

Test(vec3, vec3_sub_positive)
{
	t_vec3	vec3 = {.ops = init_ops()};
	t_vec3	v1 = {.x = 1.0, .y = 2.0, .z = 3.0};
	t_vec3	v2 = {.x = 1.0, .y = 2.0, .z = 3.0};
	t_vec3	result;

	result = vec3.ops->sub(v1, v2);
	cr_assert_float_eq(result.x, 0.0, 0.001, "X component is not correct");
	cr_assert_float_eq(result.y, 0.0, 0.001, "Y component is not correct");
	cr_assert_float_eq(result.z, 0.0, 0.001, "Z component is not correct");
}

