/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec3_cross.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:31:13 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/31 16:48:59 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

Test(vec3, test_vec3_cross)
{
	t_vec3	v1 = {.x = 1.0, .y = 2.0, .z = 3.0};
	t_vec3	v2 = {.x = 4.0, .y = 5.0, .z = 6.0};
	t_vec3	result;

	result = vec3_cross(v1, v2);
	cr_assert_float_eq(result.x, -3.0, 0.001, "Cross product x is not correct");
	cr_assert_float_eq(result.y, 6.0, 0.001, "Cross product y is not correct");
	cr_assert_float_eq(result.z, -3.0, 0.001, "Cross product z is not correct");
}

Test(vec3, test_vec3_cross_negative)
{
	t_vec3	v1 = {.x = -1.0, .y = -2.0, .z = -3.0};
	t_vec3	v2 = {.x = -4.0, .y = -5.0, .z = -6.0};
	t_vec3	result;

	result = vec3_cross(v1, v2);
	cr_assert_float_eq(result.x, -3.0, 0.001, "Cross product x is not correct");
	cr_assert_float_eq(result.y, 6.0, 0.001, "Cross product y is not correct");
	cr_assert_float_eq(result.z, -3.0, 0.001, "Cross product z is not correct");
}

Test(vec3, test_vec3_cross_zero)
{
	t_vec3	v1 = {.x = 0.0, .y = 0.0, .z = 0.0};
	t_vec3	v2 = {.x = 0.0, .y = 0.0, .z = 0.0};
	t_vec3	result;

	result = vec3_cross(v1, v2);
	cr_assert_float_eq(result.x, 0.0, 0.001, "Cross product x is not correct");
	cr_assert_float_eq(result.y, 0.0, 0.001, "Cross product y is not correct");
	cr_assert_float_eq(result.z, 0.0, 0.001, "Cross product z is not correct");
}
