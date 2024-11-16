/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:16:59 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 15:18:34 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_putreal(int fd, t_real real)
{
	t_real	frac_part;
	int		i;
	int		ret;

	ft_putnbr_fd((int)real, fd);
	if ((real - (int)real) < EPSILON)
		return ;
	ret = write(fd, ".", 1);
	if (ret == -1)
		return ;
	frac_part = real - (int)real;
	i = 0;
	while (i < 2)
	{
		frac_part *= 10;
		ft_putnbr_fd((int)frac_part, fd);
		frac_part = frac_part - (int)frac_part;
		i++;
	}
}

void	ft_putcolor(int fd, int color)
{
	int	ret;

	ft_putnbr_fd(get_r(color), fd);
	ret = write(fd, ",", 1);
	ft_putnbr_fd(get_g(color), fd);
	ret = write(fd, ",", 1);
	ft_putnbr_fd(get_b(color), fd);
	if (ret == -1)
		return ;
}

void	ft_putvector(int fd, t_vec3 vec)
{
	int	ret;
	ft_putreal(fd, vec.x);
	ret = write(fd, ",", 1);
	ft_putreal(fd, vec.y);
	ret = write(fd, ",", 1);
	ft_putreal(fd, vec.z);
	if (ret == -1)
		return ;
}
