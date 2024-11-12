/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:33:58 by mman          #+#    #+#             */
/*   Updated: 2024/02/20 11:38:54 by mman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/// @brief computes the square of the input parameter
/// @param value given number
/// @return square of the input
t_real	pow2(t_real value)
{
	return (value * value);
}

t_real	ft_abs(t_real value)
{
	if (value >= 0)
		return (value);
	return (-value);
}

t_real	norm2(t_vec3 vector)
{
	return (pow2(vector.x) + pow2(vector.y) + pow2(vector.z));
}
