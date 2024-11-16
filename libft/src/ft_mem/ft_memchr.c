/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:16:02 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 14:55:26 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

// scans N bytes from S for first instance of C
// return pointer to the matching byte or NULL

char	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t;
	unsigned char	uc;

	t = (unsigned char *) s;
	uc = (unsigned char) c;
	while (n--)
	{
		if (*t == uc)
			return ((char *) t);
		t++;
	}
	return (NULL);
}
