/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:08:04 by mman              #+#    #+#             */
/*   Updated: 2023/11/20 21:17:15 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_atoi_base(const char *nptr, const char *base)
{
	int	neg;
	int	result;
	int	nbase;

	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r')
		nptr++;
	neg = 1;
	if (*nptr == '-')
	{
		neg = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	nbase = ft_strlen(base);
	result = 0;
	while (nptr && *nptr && ft_strchr(base, *nptr))
	{
		result = result * nbase + ft_strchr(base, *nptr) - base;
		nptr++;
	}
	return (neg * result);
}
