/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec3_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:18:21 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/31 16:59:45 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

Test(vec3, test_vec3_dot)
{
	t_vec3	vec3 = {.ops = init_ops()};
	t_vec3	v1 = {.x = 1.0, .y = 2.0, .z = 3.0};
	t_vec3	v2 = {.x = 4.0, .y = 5.0, .z = 6.0};
	double	result;

	result = vec3.ops->dot(v1, v2);
	cr_assert_float_eq(result, 32.0, 0.001, "Dot product is not correct");
}

Test(vec3, test_vec3_dot_negative)
{
	t_vec3	vec3 = {.ops = init_ops()};
	t_vec3	v1 = {.x = -1.0, .y = -2.0, .z = -3.0};
	t_vec3	v2 = {.x = -4.0, .y = -5.0, .z = -6.0};
	double	result;

	result = vec3.ops->dot(v1, v2);
	cr_assert_float_eq(result, 32.0, 0.001, "Dot product is not correct");
}

Test(vec3, test_vec3_dot_zero)
{
	t_vec3	vec3 = {.ops = init_ops()};
	t_vec3	v1 = {.x = 0.0, .y = 0.0, .z = 0.0};
	t_vec3	v2 = {.x = 0.0, .y = 0.0, .z = 0.0};
	double	result;

	result = vec3.ops->dot(v1, v2);
	cr_assert_float_eq(result, 0.0, 0.001, "Dot product is not correct");
}
