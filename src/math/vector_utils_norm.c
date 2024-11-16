/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_norm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:06:49 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 15:16:57 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/// @brief 		computes the norm (length) of given vector.
/// @param vec 	given vector
/// @return 	the norm of vec, as an unsigned t_real.
t_real	norm(const t_vec3 vec)
{
	return (sqrt(pow2(vec.x) + pow2(vec.y) + pow2(vec.z)));
}

/// @brief 			normalizes a given vector.
/// @param vec		given vector.
/// @param result 	normalized vector, or 0 vector if norm of vec is 0.
t_vec3	normalize(const t_vec3 vec)
{
	t_real	scalar;

	if (norm(vec) != 0)
		scalar = 1 / norm(vec);
	else
		scalar = 0;
	return (multiply(vec, scalar));
}
