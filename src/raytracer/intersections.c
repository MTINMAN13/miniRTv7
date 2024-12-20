/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:16:59 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 15:18:22 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	compute_plane_intersection(t_ray *ray, t_object *plane)
{
	t_real	denom;
	t_real	scalar;

	denom = dot(ray->direction, plane->direction);
	if (fabs(denom) < EPSILON)
		return ;
	scalar = dot(subtract(plane->center, ray->origin), plane->direction);
	scalar /= denom;
	if (scalar <= 0
		|| (ray->intersection != -1 && scalar > ray->intersection))
		return ;
	ray->object = plane;
	ray->intersection = scalar;
	ray->normal = plane->direction;
	if (dot(ray->direction, plane->direction) > 0)
		ray->normal = multiply(plane->direction, -1);
}

static t_real	compute_scalar(t_real t[2], t_real abc[3], t_real delta)
{
	t[0] = (-abc[1] - sqrt(delta)) / (2.0 * abc[0]);
	t[1] = (-abc[1] + sqrt(delta)) / (2.0 * abc[0]);
	if (t[0] < t[1] && t[0] >= EPSILON)
		return (t[0]);
	return (t[1]);
}

void	compute_sphere_intersection(t_ray *ray, t_object *sphere)
{
	t_vec3	oc;
	t_real	abc[3];
	t_real	delta;
	t_real	scalar;
	t_real	t[2];

	oc = subtract(ray->origin, sphere->center);
	abc[0] = dot(ray->direction, ray->direction);
	abc[1] = 2.0 * dot(oc, ray->direction);
	abc[2] = dot(oc, oc) - pow2(sphere->radius);
	delta = pow2(abc[1]) - 4 * abc[0] * abc[2];
	if (delta < EPSILON)
		return ;
	scalar = compute_scalar(t, abc, delta);
	if (scalar < EPSILON
		|| (ray->intersection != -1 && scalar > ray->intersection))
		return ;
	ray->object = sphere;
	ray->intersection = scalar;
	ray->normal = add(get_hitpoint(ray), ray->origin);
	ray->normal = normalize(subtract(ray->normal, sphere->center));
	if (dot(ray->normal, ray->direction) > 0)
		ray->normal = multiply(ray->normal, -1);
}

void	compute_disk_intersection(t_ray *ray, t_object *disk)
{
	t_real	d;
	t_real	dot_ray_disk;

	dot_ray_disk = dot(ray->direction, disk->direction);
	if (ft_abs(dot_ray_disk) < EPSILON)
		return ;
	d = compute_d(ray, disk, subtract(disk->center, ray->origin), dot_ray_disk);
	if ((d > 0 && !ray->object) || (d > 0 && d < ray->intersection))
	{
		ray->object = disk;
		ray->intersection = d;
		ray->normal = multiply(disk->direction, -1);
	}
	return ;
}
