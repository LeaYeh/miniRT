/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec3_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:18:21 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/26 14:34:27 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

Test(vec3, test_vec3_dot)
{
	t_vec3	*a;
	t_vec3	*b;
	double	result;

	a = create_vec3(1.0, 2.0, 3.0);
	b = create_vec3(4.0, 5.0, 6.0);
	result = vec3_dot(*a, *b);

	cr_assert_float_eq(result, 32.0, 0.001, "Dot product is not correct");
}

Test(vec3, test_vec3_dot_negative)
{
	t_vec3	*a;
	t_vec3	*b;
	double	result;

	a = create_vec3(-1.0, -2.0, -3.0);
	b = create_vec3(-4.0, -5.0, -6.0);
	result = vec3_dot(*a, *b);

	cr_assert_float_eq(result, 32.0, 0.001, "Dot product is not correct");
}

Test(vec3, test_vec3_dot_zero)
{
	t_vec3	*a;
	t_vec3	*b;
	double	result;

	a = create_vec3(0, 0, 0);
	b = create_vec3(0, 0, 0);
	result = vec3_dot(*a, *b);

	cr_assert_float_eq(result, 0.0, 0.001, "Dot product is not correct");
}
