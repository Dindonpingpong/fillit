/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:08:23 by rkina             #+#    #+#             */
/*   Updated: 2019/11/03 21:25:46 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_solve(int *coords, int min_size, int tet)
{
	while (ft_overlay(coords, tet))
		ft_move(coords, tet, 'y');
	if (ft_check_over_map(coords, tet, min_size))
	{
		coords = ft_move_zero_position(coords, tet);
		while (ft_overlay(coords, tet))
			ft_move(coords, tet, 'x');
		if (ft_check_over_map(coords, tet, min_size))
		{
			coords = ft_move_zero_position(coords, tet);
			while (ft_overlay(coords, tet))
			{
				ft_move(coords, tet, 'y');
				while (ft_overlay(coords, tet))
					ft_move(coords, tet, 'x');
				if (ft_check_over_map(coords, tet, min_size))
					ft_move_zero_position_x(coords, tet);
			}
			if (ft_check_over_map(coords, tet, min_size))
			{
				ft_move_zero_position(coords, tet);
				return (0);
			}
		}
	}
	return (1);
}
