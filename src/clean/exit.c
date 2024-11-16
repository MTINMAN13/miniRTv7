/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:14:45 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 15:14:55 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

// static void ft_freetab(void **tab)
// {
//     int i;

//     if (!tab)
//         return;
//     i = 0;
//     while (tab[i])
//     {
//         free(tab[i]);
//         i++;
//     }
//     free(tab);
// }

void	exit_minirt_build(t_build *build, char *message, int status)
{
	if (build->tab)
		ft_freetab((void **)build->tab);
	if (build->line)
		free(build->line);
	if (build->fd)
		close(build->fd);
	if (build->scene->objects)
		free_objects(build->scene->objects);
	if (build->scene->spotlights)
		free_spotlights(build->scene->spotlights);
	if (status)
		error_msg(message, build->line_idx);
	exit(status);
}

void	protect_malloc(t_build *build, void *check_ptr)
{
	if (check_ptr == NULL)
		exit_minirt_build(build, MALLOC_FAILED, MALLOC_EXITCODE);
}
