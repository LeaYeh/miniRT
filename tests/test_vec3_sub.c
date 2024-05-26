/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec3_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:58:30 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/26 14:34:27 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

Test(vec3, vec3_sub_zero)
{
	t_vec3	*a;
	t_vec3	*b;
	t_vec3	*result;

	a = create_vec3(1.0, 2.0, 3.0);
	b = create_vec3(0, 0, 0);
	result = a->sub(*a, *b);

	cr_assert_float_eq(result->x, 1.0, 0.001, "X component is not correct");
	cr_assert_float_eq(result->y, 2.0, 0.001, "Y component is not correct");
	cr_assert_float_eq(result->z, 3.0, 0.001, "Z component is not correct");
}

Test(vec3, vec3_sub_negative)
{
	t_vec3	*a;
	t_vec3	*b;
	t_vec3	*result;

	a = create_vec3(1.0, 2.0, 3.0);
	b = create_vec3(-1.0, -2.0, -3.0);
	result = a->sub(*a, *b);

	cr_assert_float_eq(result->x, 2.0, 0.001, "X component is not correct");
	cr_assert_float_eq(result->y, 4.0, 0.001, "Y component is not correct");
	cr_assert_float_eq(result->z, 6.0, 0.001, "Z component is not correct");
}

Test(vec3, vec3_sub_positive)
{
	t_vec3	*a;
	t_vec3	*b;
	t_vec3	*result;

	a = create_vec3(1.0, 2.0, 3.0);
	b = create_vec3(1.0, 2.0, 3.0);
	result = a->sub(*a, *b);

	cr_assert_float_eq(result->x, 0.0, 0.001, "X component is not correct");
	cr_assert_float_eq(result->y, 0.0, 0.001, "Y component is not correct");
	cr_assert_float_eq(result->z, 0.0, 0.001, "Z component is not correct");
}

