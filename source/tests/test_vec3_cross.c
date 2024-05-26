/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec3_cross.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:31:13 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/26 14:40:54 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

Test(vec3, test_vec3_cross)
{
	t_vec3	*a;
	t_vec3	*b;
	t_vec3	*result;

	a = create_vec3(1.0, 2.0, 3.0);
	b = create_vec3(4.0, 5.0, 6.0);
	result = vec3_cross(*a, *b);

	cr_assert_float_eq(result->x, -3.0, 0.001, "Cross product x is not correct");
	cr_assert_float_eq(result->y, 6.0, 0.001, "Cross product y is not correct");
	cr_assert_float_eq(result->z, -3.0, 0.001, "Cross product z is not correct");
}

Test(vec3, test_vec3_cross_negative)
{
	t_vec3	*a;
	t_vec3	*b;
	t_vec3	*result;

	a = create_vec3(-1.0, -2.0, -3.0);
	b = create_vec3(-4.0, -5.0, -6.0);
	result = vec3_cross(*a, *b);

	cr_assert_float_eq(result->x, -3.0, 0.001, "Cross product x is not correct");
	cr_assert_float_eq(result->y, 6.0, 0.001, "Cross product y is not correct");
	cr_assert_float_eq(result->z, -3.0, 0.001, "Cross product z is not correct");
}

Test(vec3, test_vec3_cross_zero)
{
	t_vec3	*a;
	t_vec3	*b;
	t_vec3	*result;

	a = create_vec3(0, 0, 0);
	b = create_vec3(0, 0, 0);
	result = vec3_cross(*a, *b);

	cr_assert_float_eq(result->x, 0.0, 0.001, "Cross product x is not correct");
	cr_assert_float_eq(result->y, 0.0, 0.001, "Cross product y is not correct");
	cr_assert_float_eq(result->z, 0.0, 0.001, "Cross product z is not correct");
}
