/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:17:08 by rkina             #+#    #+#             */
/*   Updated: 2019/11/07 17:58:26 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_answer(int *coords, int size, int start, int len)
{
	while (!(ft_check_over_map(coords, start, size, 'y')))
	{
		while (!(ft_check_over_map(coords, start, size, 'x')))
		{
			if (!(ft_overlay(coords, start)))
			{
				if (start == len)
					return (1);
				if (!(ft_answer(coords, size, start + 1, len)))
					ft_move_zero_position(coords, start + 1);
				else
					return (1);
			}
			ft_move(coords, start, 'x');
		}
		ft_move_zero_position_x(coords, start);
		ft_move(coords, start, 'y');
	}
	return (0);
}

int		ft_solve(int *coords, int start, int size, int len)
{
	while (!(ft_answer(coords, size, start, len)))
	{
		ft_move_zero_position_all(coords, len);
		size++;
	}
	return (0);
}

void	ft_fillit(t_flist **head, int *coord_of_sharp,
int min_size, int nbrs_tetra)
{
	int start;

	start = 1;
	ft_solve(coord_of_sharp, start, min_size, nbrs_tetra);
	ft_add_to_fin_list(head, coord_of_sharp, nbrs_tetra);
}
