/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:00:10 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 14:52:21 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	s;
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	s = nmemb * size;
	if (s / size != nmemb)
		return (NULL);
	ptr = malloc(s);
	if (ptr != NULL)
		ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
