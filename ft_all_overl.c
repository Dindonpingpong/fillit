/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_overl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:17:08 by rkina             #+#    #+#             */
/*   Updated: 2019/11/03 22:42:02 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_ans(int *coords, int size, int end)
{
	int start, leaf, i, n;

	leaf = 2;
	start = 2;
	i = 0;
	int j;
	n = 0;
	while (i != -3)
	{
		while (start <= end)
		{
			if (!(ft_solve(coords, size, start)))
			{
				if (start == end)
				{
					printf("swap %d\n", end);
					if (n == 2)
					{
						ft_swap_tet(coords, start - 1, start + 1);
					}
					else
						ft_swap_tet(coords, end - 1, end);
					n++;
					j++;
				}
				else
				{
					ft_swap_tet(coords, start, start + 1);
				}
				//start = 2;
				i = -1;
				break ;
			}
			start++;
			i++;
		}
		if (i > -1)
			i = -3;
		if ((leaf == end) && (i == -1))
		{
			size++;
			ft_ans(coords, size, end);
			break ;
		}
		if ((leaf < end) && (i == -1))
		{
			j = 0;
			i = 0;
			start = 2;
			ft_swap_tet(coords, 1, leaf);
			leaf++;
		}
	}
}

void	ft_all_overl(t_flist **head, int *coord_of_sharp, int min_size, int nbrs_tetra)
{
	if (nbrs_tetra == 1)
		ft_add_to_fin_list(head, coord_of_sharp, nbrs_tetra, min_size);
	else
	{
		ft_ans(coord_of_sharp, min_size, nbrs_tetra);
		//print map
	}
//----------------------------------------------------------------------------------------
}
