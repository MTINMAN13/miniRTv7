/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:16:59 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 15:17:45 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	get_vec3(t_build *build, char *numbers)
{
	char	**tab;
	t_real	x;
	t_real	y;
	t_real	z;

	tab = ft_split(numbers, ',');
	protect_malloc(build, (void *)tab);
	if (ft_tablen((void **)tab) != 3)
	{
		ft_freetab((void **)tab);
		exit_minirt_build(build, PARSING_ERROR, PARSING_EXITCODE);
	}
	x = get_real(build, tab[0]);
	y = get_real(build, tab[1]);
	z = get_real(build, tab[2]);
	ft_freetab((void **)tab);
	return ((t_vec3){x, y, z});
}

int	get_color(t_build *build, char *colorstr)
{
	char	**tab;
	int		rgb[3];

	tab = ft_split(colorstr, ',');
	protect_malloc(build, tab);
	if (ft_tablen((void **)tab) != 3)
	{
		ft_freetab((void **)tab);
		exit_minirt_build(build, "invalid color vector", PARSING_EXITCODE);
	}
	rgb[0] = ft_atoi(tab[0]);
	rgb[1] = ft_atoi(tab[1]);
	rgb[2] = ft_atoi(tab[2]);
	ft_freetab((void **)tab);
	if ((rgb[0] < 0 || rgb[0] > 255)
		|| (rgb[1] < 0 || rgb[1] > 255)
		|| (rgb[2] < 0 || rgb[2] > 255))
		exit_minirt_build(build, "invalid color values", PARSING_EXITCODE);
	return (get_rgba(rgb[0], rgb[1], rgb[2], 0xff));
}

int	ft_countchar(const char *str, char c)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == c)
			cnt++;
		str++;
	}
	return (cnt);
}
