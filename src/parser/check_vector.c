/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:16:59 by mman              #+#    #+#             */
/*   Updated: 2024/11/16 15:17:24 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	is_vector(t_build *build, char *str)
{
	char	**tab;

	if (ft_countchar(str, ',') != 2)
		return (0);
	tab = ft_split(str, ',');
	protect_malloc(build, tab);
	if (ft_tablen((void **)tab) != 3 || !is_real(tab[0]) || \
		!is_real(tab[1]) || !is_real(tab[2]))
	{
		ft_freetab((void **)tab);
		return (0);
	}
	ft_freetab((void **)tab);
	return (1);
}
