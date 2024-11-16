/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:50:01 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 15:14:57 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	error_msg(const char *info, int line_idx)
{
	char	*errno_readable;
	int		i;

	i = write(STDERR_FILENO, "Error\n", 6);
	i = write(STDERR_FILENO, "miniRT: ", 8);
	if (!ft_strcmp(info, PARSING_ERROR))
	{
		i = write(STDERR_FILENO, info, ft_strlen(info));
		ft_putnbr_fd(line_idx, STDERR_FILENO);
	}
	else if (info)
		i = write(STDERR_FILENO, info, ft_strlen(info));
	errno_readable = strerror(errno);
	if (errno)
	{
		i = write(STDERR_FILENO, ": ", 2);
		i = write(STDERR_FILENO, errno_readable, ft_strlen(errno_readable));
	}
	i = write(STDERR_FILENO, "\n", 1);
	return (i);
}

void	free_objects(t_object *head)
{
	t_object	*next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

void	free_spotlights(t_spotlight *head)
{
	t_spotlight	*next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

void	exit_minirt(t_minirt *minirt, char *message, int status)
{
	if (minirt->scene->objects)
		free_objects(minirt->scene->objects);
	if (status)
		error_msg(message, 0);
	exit(status);
}
