/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_over.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:51:27 by rkina             #+#    #+#             */
/*   Updated: 2019/11/07 15:23:21 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_overlay(int *coords, int nbr_tet)
{
	int n_check;
	int i;
	int j;

	n_check = nbr_tet - 1;
	if (nbr_tet == 1)
		return (0);
	while (n_check > 0)
	{
		j = (nbr_tet - 1) * 8;
		while (j < (nbr_tet * 8))
		{
			i = (n_check - 1) * 8;
			while (i < n_check * 8)
			{
				if (coords[i] == coords[j] && coords[i + 1] == coords[j + 1])
					return (1);
				i += 2;
			}
			j += 2;
		}
		n_check--;
	}
	return (0);
}

int		ft_check_over_map(int *crds, int nbrs_tet, int min_size, char x_y)
{
	int	i;

	i = (x_y == 'x') ? ((nbrs_tet - 1) * 8) : ((nbrs_tet - 1) * 8 + 1);
	while (i < nbrs_tet * 8)
	{
		if (crds[i] + 1 > min_size)
			return (1);
		i += 2;
	}
	return (0);
}
