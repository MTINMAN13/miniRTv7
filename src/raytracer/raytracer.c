/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:16:59 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 16:51:33 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	compute_viewport(t_minirt *minirt)
{
	t_camera	*camera;
	t_real		aspect_ratio;

	camera = &minirt->scene->camera;
	camera->right = normalize(cross(camera->direction, camera->up));
	camera->up = normalize(cross(camera->right, camera->direction));
	camera->height = 2.0 * tan(camera->fov / 2);
	aspect_ratio = minirt->image->width / minirt->image->height;
	camera->width = aspect_ratio * camera->height;
}

void	ft_compute_ray_object_intersection(t_minirt *minirt, t_ray *ray)
{
	t_object	*curr;

	curr = minirt->scene->objects;
	while (curr)
	{
		if (curr->type == PLANE)
			compute_plane_intersection(ray, curr);
		if (curr->type == SPHERE)
			compute_sphere_intersection(ray, curr);
		if (curr->type == CYLINDER)
			compute_cyl_intersection(ray, curr);
		if (curr->type == DISK)
			compute_disk_intersection(ray, curr);
		curr = curr->next;
	}
}

void	render_scene(t_minirt *minirt)
{
	uint32_t	x;
	uint32_t	y;

	y = -1;
	while (++y < minirt->image->height)
	{
		x = -1;
		while (++x < minirt->image->width)
			ft_put_pixel(minirt->image, x, y, anti_alias(minirt, x, y));
	}
}

void	ft_raytracer(void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	compute_viewport(minirt);
	render_scene(minirt);
}

// void	compute_viewport(t_minirt *minirt)
// {
// 	t_camera	*camera;
// 	t_real		aspect_ratio;

// 	camera = &minirt->scene->camera;
// 	camera->right = normalize(cross(camera->direction, camera->up));
// 	camera->up = normalize(cross(camera->right, camera->direction));
// 	camera->height = 2.0 * tan(camera->fov / 2);
// 	aspect_ratio = minirt->image->width / minirt->image->height;
// 	camera->width = aspect_ratio * camera->height;
// }

// void	ft_compute_ray_object_intersection(t_minirt *minirt, t_ray *ray)
// {
// 	t_object	*curr;

// 	curr = minirt->scene->objects;
// 	while (curr)
// 	{
// 		if (curr->type == PLANE)
// 			compute_plane_intersection(ray, curr);
// 		if (curr->type == SPHERE)
// 			compute_sphere_intersection(ray, curr);
// 		if (curr->type == CYLINDER)
// 			compute_cyl_intersection(ray, curr);
// 		if (curr->type == DISK)
// 			compute_disk_intersection(ray, curr);
// 		curr = curr->next;
// 	}
// }

// void	*init_thread(void *param)
// {
// 	uint32_t	x;
// 	uint32_t	y;
// 	uint32_t	max_y;
// 	t_minirt	*minirt;
// 	t_row		*group;

// 	group = (t_row *)param;
// 	minirt = group->minirt;
// 	y = group->index * *group->rows_per_group - 1;
// 	if (group->index == CORES - 1)
// 		max_y = minirt->image->height;
// 	else
// 		max_y = y + 1 + *group->rows_per_group;
// 	while (++y < max_y)
// 	{
// 		x = -1;
// 		while (++x < minirt->image->width)
// 			ft_put_pixel(minirt->image, x, y, anti_alias(minirt, x, y));
// 	}
// 	return (NULL);
// }

// void	ft_raytracer(void *param)
// {
// 	t_minirt	*minirt;
// 	uint32_t	i;
// 	t_row		groups[CORES];
// 	pthread_t	threads[CORES];
// 	uint32_t	rows_per_group;

// 	minirt = (t_minirt *)param;
// 	compute_viewport(minirt);
// 	rows_per_group = minirt->image->height / CORES;
// 	i = -1;
// 	while (++i < CORES)
// 	{
// 		groups[i].index = i;
// 		groups[i].minirt = minirt;
// 		groups[i].rows_per_group = &rows_per_group;
// 		pthread_create(&(threads[i]), NULL, &init_thread, &groups[i]);
// 	}
// 	i = -1;
// 	while (++i < CORES)
// 		pthread_join(threads[i], NULL);
// }
