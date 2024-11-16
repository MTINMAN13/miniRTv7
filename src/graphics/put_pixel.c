/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:06:49 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 15:16:50 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/// @brief Set pixel color in the given image at (x, y) coordinates.
/// @param image Pointer to mlx_image_t representing the image.
/// @param x The x-coordinate.
/// @param y The y-coordinate.
/// @param color 32-bit integer representing RGBA color.
void	ft_put_pixel(mlx_image_t *image, unsigned int x, \
	unsigned int y, int color)
{
	unsigned char	*pixel;

	if (image && x < image->width && y < image->height)
	{
		pixel = &image->pixels[(y * image->width + x) * sizeof(int)];
		*(pixel++) = (unsigned char)get_r(color);
		*(pixel++) = (unsigned char)get_g(color);
		*(pixel++) = (unsigned char)get_b(color);
		*(pixel++) = (unsigned char)get_a(color);
	}
}
