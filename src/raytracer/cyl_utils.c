/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:16:59 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 15:18:16 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_cyl	init_ints_struct(t_ray	*ray, t_object *cyl)
{
	t_cyl	ints;

	ints.nxa = cross(ray->direction, cyl->direction);
	ints.b = subtract(cyl->center, ray->origin);
	ints.b_x_a = cross(ints.b, cyl->direction);
	ints.d_cap = -1;
	ints.d_hull = -1;
	return (ints);
}

int	get_min_positive(t_real value0, t_real value1)
{
	if (value0 >= 0 && (value1 < 0 || value0 <= value1))
		return (0);
	if (value1 >= 0)
		return (1);
	return (-1);
}

int	is_first_visible(t_real a, t_real b, t_real scalar)
{
	if (a < 0 || (scalar != -1 && a > scalar))
		return (0);
	return (b < 0 || a <= b);
}
