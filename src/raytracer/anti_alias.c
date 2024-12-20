/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_alias.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:16:59 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 16:52:44 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	set_rgb_array(int rgb[3], int r, int g, int b)
{
	if (r == -1)
	{
		rgb[0] = 0;
		rgb[1] = 0;
		rgb[2] = 0;
	}
	else
	{
		rgb[0] += r;
		rgb[1] += g;
		rgb[2] += b;
	}
}

int	anti_alias(t_minirt *minirt, uint32_t x, uint32_t y)
{
	int		color;
	int		a[3];
	t_ray	camera_ray;
	int		i;
	int		j;

	i = -minirt->antialias - 1;
	set_rgb_array(a, -1, -1, -1);
	while (++i < minirt->antialias + 1)
	{
		j = -minirt->antialias - 1;
		while (++j < minirt->antialias + 1)
		{
			compute_camera_ray(minirt, (t_real)x + (t_real)j
				/ (2 * (minirt->antialias + 1)), (t_real)y
				+ (t_real)i / (2 * (minirt->antialias + 1)), &camera_ray);
			ft_compute_ray_object_intersection(minirt, &camera_ray);
			color = compute_color(minirt, &camera_ray);
			set_rgb_array(a, get_r(color), get_g(color), get_b(color));
		}
	}
	return (get_rgba(a[0] / minirt->num, a[1] / minirt->num, a[2]
			/ minirt->num, 255));
}
