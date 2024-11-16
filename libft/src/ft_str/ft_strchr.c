/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:36:19 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 14:57:45 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//    The strchr() function returns a pointer to the first occurrence
//    of the character c in the string s.
//    WE return a pointer to the
//    matched character or NULL if the character is not found.  The
//    terminating null byte is considered part of the string, so that
//    if c is specified as '\0', these functions return a pointer to
//    the terminator.

#include <string.h>
#include "../../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char) c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *) s);
}
