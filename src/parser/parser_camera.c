/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:16:59 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 15:17:27 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	parse_camera(t_build *build)
{
	if (ft_tablen((void **)build->tab) != 4
		|| !is_vector(build, build->tab[1])
		|| !is_vector(build, build->tab[2])
		|| !is_angle(build, build->tab[3]))
		exit_minirt_build(build, PARSING_ERROR, PARSING_EXITCODE);
	build->scene->camera.viewpoint = get_vec3(build, build->tab[1]);
	build->scene->camera.direction = normalize(get_vec3(build, build->tab[2]));
	build->scene->camera.fov = get_real(build, build->tab[3]);
	build->scene->camera.fov *= M_PI / 180;
	return (1);
}
