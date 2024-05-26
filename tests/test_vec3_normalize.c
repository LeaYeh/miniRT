/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec3_normalize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:43:27 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/26 14:43:59 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

Test(vec3, test_vec3_normalize)
{
    t_vec3	*a;
    t_vec3	*result;

    a = create_vec3(1.0, 2.0, 3.0);
    result = vec3_normalize(*a);

    cr_assert_float_eq(result->x, 0.267261, 0.001, "Normalized x is not correct");
    cr_assert_float_eq(result->y, 0.534522, 0.001, "Normalized y is not correct");
    cr_assert_float_eq(result->z, 0.801784, 0.001, "Normalized z is not correct");
}

Test(vec3, test_vec3_normalize_negative)
{
    t_vec3	*a;
    t_vec3	*result;

    a = create_vec3(-1.0, -2.0, -3.0);
    result = vec3_normalize(*a);

    cr_assert_float_eq(result->x, -0.267261, 0.001, "Normalized x is not correct");
    cr_assert_float_eq(result->y, -0.534522, 0.001, "Normalized y is not correct");
    cr_assert_float_eq(result->z, -0.801784, 0.001, "Normalized z is not correct");
}
