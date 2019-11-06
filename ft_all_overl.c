/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_overl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:17:08 by rkina             #+#    #+#             */
/*   Updated: 2019/11/06 14:10:52 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	ft_ans(int *coords, int size, int start)
{
	while (!(ft_check_over_map(coords, start, size, 'y')))
	{
		while (!(ft_check_over_map(coords, start, size, 'x')))
		{
			if (!(ft_overlay(coords, start)))
			{
				start++;
				printf("%d",start);
				if (!(ft_ans(coords, size, start)))
				{
					return (1);
				}
				else
				{
					start--;
				}
			}
			ft_move(coords, start, 'x');
		}
		ft_move_zero_position_x(coords, start);
		ft_move(coords, start, 'y');
	}
	ft_move_zero_position_all(coords, 2);
	return (0);
}

int		ft_solve(int *coords, int start, int size, int len)
{
	while (!(ft_ans(coords, size, start)))
	{
		ft_move_zero_position_all(coords, len);
		size++;
	}
	return (0);
}

int	ft_all_overl(t_flist **head, int *coord_of_sharp, int min_size, int nbrs_tetra)
{
	int start;

	start  = 1;
	if (nbrs_tetra == 19)
		ft_add_to_fin_list(head, coord_of_sharp, nbrs_tetra, min_size);
	else
	{
		ft_solve(coord_of_sharp, start, min_size, nbrs_tetra);
	}
	return (0);
}