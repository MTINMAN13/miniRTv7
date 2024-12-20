/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cyl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:16:59 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 15:17:33 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	check_cyl_tab(t_build *build)
{
	char		**tab;

	tab = build->tab;
	if (ft_tablen((void **)tab) != 8)
		exit_minirt_build(build, PARSING_ERROR, PARSING_EXITCODE);
	if (!is_vector(build, tab[1]))
		exit_minirt_build(build, PARSING_ERROR, PARSING_EXITCODE);
	if (!is_vector(build, tab[2]))
		exit_minirt_build(build, PARSING_ERROR, PARSING_EXITCODE);
	if (!is_posnum(build, tab[3]))
		exit_minirt_build(build, PARSING_ERROR, PARSING_EXITCODE);
	if (!is_posnum(build, tab[4]))
		exit_minirt_build(build, PARSING_ERROR, PARSING_EXITCODE);
	if (!is_color(build, tab[5]))
		exit_minirt_build(build, PARSING_ERROR, PARSING_EXITCODE);
	if (!is_ratio(build, build->tab[6]))
		exit_minirt_build(build, PARSING_ERROR, PARSING_EXITCODE);
	if (!is_posnum(build, build->tab[7]))
		exit_minirt_build(build, PARSING_ERROR, PARSING_EXITCODE);
}

t_real	get_radius(t_build *build, char *rad)
{
	t_real	ret;

	ret = get_real(build, rad) / 2;
	if (ret <= 0)
		exit_minirt_build(build,
			"cyl radius must be more than 0", PARSING_EXITCODE);
	return (ret);
}

static t_real	get_cyl_height(t_build *build, char *height)
{
	t_real	ret;

	ret = get_real(build, height);
	if (ret <= 0)
		exit_minirt_build(build,
			"cyl height must be more than 0", PARSING_EXITCODE);
	return (ret);
}

t_vec3	compute_up_vector(t_build *build, t_vec3 direction)
{
	t_vec3	right;

	right = get_vec3(build, "0,0,1");
	if (norm(cross(right, direction)) < EPSILON)
	{
		right.z = 0;
		right.x = -direction.z;
	}
	return (cross(direction, right));
}

void	parse_cyl(t_build *build)
{
	t_object	*cyl;
	char		**tab;
	t_scene		*scene;

	tab = build->tab;
	scene = build->scene;
	check_cyl_tab(build);
	cyl = malloc(sizeof(t_object));
	protect_malloc(build, cyl);
	cyl->type = CYLINDER;
	cyl->center = get_vec3(build, tab[1]);
	cyl->direction = normalize(get_vec3(build, tab[2]));
	cyl->radius = get_radius(build, tab[3]);
	cyl->height = get_cyl_height(build, tab[4]);
	cyl->color = get_color(build, tab[5]);
	cyl->up = compute_up_vector(build, cyl->direction);
	cyl->diffuse = 1.0;
	cyl->shininess = 0.0;
	cyl->diffuse = get_real(build, tab[6]);
	cyl->shininess = get_real(build, tab[7]);
	cyl->next = scene->objects;
	scene->objects = cyl;
}
