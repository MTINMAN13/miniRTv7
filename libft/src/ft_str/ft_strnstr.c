/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:41:29 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 14:59:16 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../../inc/libft.h"
// locates first occurrence of null terminated string little in string big
// where no more than len characters are searched (not searched after a '\0')

// if little is empty string, big is returned
// if litztle occurs nowhere in big, NULL is returned
// otherwise pointer to the first char of first occured little is returned

int	ft_match(const char *big, const char *little, size_t len)
{
	while (len && *big == *little)
	{
		if (*big == '\0')
			return (1);
		big++;
		little++;
		len--;
	}
	return (*little == '\0');
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (*little == 0)
		return ((char *) big);
	while (len && *big)
	{
		if (ft_match(big, little, len))
			return ((char *) big);
		big++;
		len--;
	}
	return (NULL);
}

char	*ft_grep(char **tab, char *word)
{
	if (!word || *word == 0)
		return (tab[0]);
	while (*tab)
	{
		if (ft_match(*tab, word, ft_strlen(*tab)))
			return (*tab);
		tab++;
	}
	return (NULL);
}
