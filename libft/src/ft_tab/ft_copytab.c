/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copytab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:39:40 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 15:00:48 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../inc/libft.h"

void	ft_copytab(void **dest, void **src)
{
	int		srclen;

	srclen = ft_tablen(src);
	ft_memcpy(dest, src, srclen);
}
