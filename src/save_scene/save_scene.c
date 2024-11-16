/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:16:59 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 15:18:46 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	write_ambient(int fd, t_minirt *minirt)
{
	int	i;

	i = write(fd, "A ", 2);
	ft_putreal(fd, minirt->scene->ambient.ratio);
	i = write(fd, " ", 1);
	ft_putcolor(fd, minirt->scene->ambient.color);
	i = write(fd, "\n", 1);
	if (i == -1)
		return ;
}

static void	write_camera(int fd, t_minirt *minirt)
{
	int	i;

	i = write(fd, "C ", 2);
	ft_putvector(fd, minirt->scene->camera.viewpoint);
	i = write(fd, " ", 1);
	ft_putvector(fd, minirt->scene->camera.direction);
	i = write(fd, " ", 1);
	ft_putnbr_fd(minirt->scene->camera.fov * 180 / M_PI, fd);
	i = write(fd, "\n", 1);
	if (i == -1)
		return ;
}

static void	write_spots(int fd, t_minirt *minirt)
{
	t_spotlight	*iter;
	int			i;

	iter = minirt->scene->spotlights;
	while (iter)
	{
		i = write(fd, "L ", 2);
		ft_putvector(fd, iter->source);
		i = write(fd, " ", 1);
		ft_putreal(fd, iter->diffuse);
		i = write(fd, " ", 1);
		ft_putcolor(fd, iter->color);
		i = write(fd, " ", 1);
		ft_putreal(fd, iter->specular);
		i = write(fd, "\n", 1);
		iter = iter->next;
	}
	if (i == -1)
		return ;
}

void	save_scene(t_minirt *minirt)
{
	int			fd;
	t_object	*iter;
	int			i;

	fd = open("scenes/output.rt", O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (fd < 0)
	{
		i = write(STDERR_FILENO, "Can't save scene\n", 17);
		return ;
	}
	write_ambient(fd, minirt);
	write_camera(fd, minirt);
	write_spots(fd, minirt);
	iter = minirt->scene->objects;
	while (iter)
	{
		write_object(fd, iter);
		iter = iter->next;
	}
	i = write(STDOUT_FILENO, "Scene saved in scenes/output.rt", 31);
	if (i == -1)
		return ;
	close(fd);
}
