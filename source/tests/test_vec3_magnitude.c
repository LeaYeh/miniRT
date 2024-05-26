/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec3_magnitude.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:41:55 by lyeh              #+#    #+#             */
/*   Updated: 2024/05/26 14:42:29 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

Test(vec3, test_vec3_magnitude)
{
    t_vec3	*a;
    double	result;

    a = create_vec3(1.0, 2.0, 3.0);
    result = vec3_magnitude(*a);

    cr_assert_float_eq(result, 3.741657, 0.001, "Magnitude is not correct");
}

Test(vec3, test_vec3_magnitude_negative)
{
    t_vec3	*a;
    double	result;

    a = create_vec3(-1.0, -2.0, -3.0);
    result = vec3_magnitude(*a);

    cr_assert_float_eq(result, 3.741657, 0.001, "Magnitude is not correct");
}

Test(vec3, test_vec3_magnitude_zero)
{
    t_vec3	*a;
    double	result;

    a = create_vec3(0, 0, 0);
    result = vec3_magnitude(*a);

    cr_assert_float_eq(result, 0.0, 0.001, "Magnitude is not correct");
}

Test(vec3, test_vec3_magnitude_one)
{
    t_vec3	*a;
    double	result;

    a = create_vec3(1.0, 1.0, 1.0);
    result = vec3_magnitude(*a);

    cr_assert_float_eq(result, 1.732051, 0.001, "Magnitude is not correct");
}
