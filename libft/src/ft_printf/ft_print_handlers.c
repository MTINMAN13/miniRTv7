/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:17:48 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 15:31:42 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	ft_putcharo(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_handle_s(char *string)
{
	int	returnvalue;

	returnvalue = 0;
	if (string == (char *) NULL)
		string = "(null)";
	while (*string)
	{
		ft_putcharo(*string);
		string++;
		returnvalue++;
	}
	return (returnvalue);
}

int	ft_handle_c(int whatever)
{
	ft_putcharo(whatever);
	return (1);
}

int	ft_print_percent(void)
{
	ft_putcharo('%');
	return (1);
}
