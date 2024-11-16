/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:16:59 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 15:18:50 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	write_direction(int fd, t_object *object)
{
	int	ret;
	ret = write(fd, " ", 1);
	if (ret == -1)
		return ;
	ft_putvector(fd, object->direction);
}

static void	write_radius(int fd, t_object *object)
{
	int	ret;
	ft_putreal(fd, object->radius * 2);
	ret = write(fd, " ", 1);
	if (ret == -1)
		return ;
}

void	write_object(int fd, t_object *object)
{
	int	ret;

	if (object->type == SPHERE)
		ret = write(fd, "sp ", 3);
	else if (object->type == PLANE)
		ret = write(fd, "pl ", 3);
	else if (object->type == CYLINDER)
		ret = write(fd, "cy ", 3);
	else if (object->type == DISK)
		ret = write(fd, "di ", 3);
	ft_putvector(fd, object->center);
	if (object->type != SPHERE)
		write_direction(fd, object);
	ret = write(fd, " ", 1);
	if (object->type != PLANE)
		write_radius(fd, object);
	if (object->type == CYLINDER)
	{
		ft_putreal(fd, object->height);
		ret = write(fd, " ", 1);
	}
	ft_putcolor(fd, object->color);
	ret = write(fd, " ", 1);
	ft_putreal(fd, object->diffuse);
	ret = write(fd, " ", 1);
	ft_putreal(fd, object->shininess);
	ret = write(fd, "\n", 1);
	if (ret == -1)
		return ;
}
