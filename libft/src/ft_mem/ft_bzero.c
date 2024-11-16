/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:25:37 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 14:52:13 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

// erases data in n bytes of the memory starting at the location
// pointed to by s            by writing zeros to that area

void	ft_bzero(void *s, size_t n)
{
	char	*t;

	t = (char *) s;
	while (n--)
		*t++ = 0;
}
