/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:06:49 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 15:16:53 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	*set_direction(t_minirt *minirt)
{
	if (minirt->mode == MODE_CAMERA)
		return (&(minirt->scene->camera.direction));
	else if (minirt->mode == MODE_OBJECT)
		return (&(minirt->obj_selected->direction));
	return (NULL);
}

t_vec3	*set_up(t_minirt *minirt)
{
	if (minirt->mode == MODE_CAMERA)
		return (&(minirt->scene->camera.up));
	else if (minirt->mode == MODE_OBJECT)
		return (&(minirt->obj_selected->up));
	return (NULL);
}
