/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:16:10 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 14:55:39 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

// copies n bytes from memory area src to memory area dest

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str_dest;
	unsigned char	*str_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	str_dest = (unsigned char *) dest;
	str_src = (unsigned char *) src;
	while (n-- > 0)
		*str_dest++ = *str_src++;
	return (dest);
}
