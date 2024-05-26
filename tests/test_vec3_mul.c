/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec3_mul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:16:51 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/26 14:34:27 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

Test(vec3, vec3_mul_one)
{
	t_vec3	*a;
	t_vec3	*result;

	a = create_vec3(1.0, 2.0, 3.0);
	result = a->mul(*a, 1.0);

	cr_assert_float_eq(result->x, 1.0, 0.001, "X component is not correct");
	cr_assert_float_eq(result->y, 2.0, 0.001, "Y component is not correct");
	cr_assert_float_eq(result->z, 3.0, 0.001, "Z component is not correct");
}

Test(vec3, vec3_mul_two)
{
	t_vec3	*a;
	t_vec3	*result;

	a = create_vec3(1.0, 2.0, 3.0);
	result = a->mul(*a, 2.0);

	cr_assert_float_eq(result->x, 2.0, 0.001, "X component is not correct");
	cr_assert_float_eq(result->y, 4.0, 0.001, "Y component is not correct");
	cr_assert_float_eq(result->z, 6.0, 0.001, "Z component is not correct");
}

Test(vec3, vec3_mul_negative)
{
	t_vec3	*a;
	t_vec3	*result;

	a = create_vec3(1.0, 2.0, 3.0);
	result = a->mul(*a, -1.0);

	cr_assert_float_eq(result->x, -1.0, 0.001, "X component is not correct");
	cr_assert_float_eq(result->y, -2.0, 0.001, "Y component is not correct");
	cr_assert_float_eq(result->z, -3.0, 0.001, "Z component is not correct");
}
