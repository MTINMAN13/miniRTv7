/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:59:40 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 14:57:54 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		size;

	size = 0;
	while (s && s[size])
		size++;
	size++;
	copy = malloc(size * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (size--)
		copy[size] = s[size];
	return (copy);
}
