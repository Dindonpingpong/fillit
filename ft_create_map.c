/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:53:57 by npetrell          #+#    #+#             */
/*   Updated: 2019/11/06 21:23:18 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		ft_print_map(int size_map, char map[size_map][size_map])
{
	int		x;
	int		y;

	x = -1;
	while (++x < size_map)
	{
		y = -1;
		while (++y < size_map)
			write(1, &map[x][y], 1);
		write(1, "\n", 1);
	}
}

void		ft_create_map(t_flist  *head, int size_map)
{
	char	map[size_map][size_map];
	int		i;
	int		x;
	int		y;

	x = -1;
	while (++x < size_map)
	{
		y = 0;
		while (y < size_map)
			map[x][y++] = '.';
	}
	while (head)
	{
		i = -2;
		while ((i += 2) < 8)
		{
			y = head->crd_sharp[i];
			x = head->crd_sharp[i + 1];
			map[x][y] = head->name;
		}
		head = head->next;
	}
	ft_print_map(size_map, map);
}



void		ft_add_to_fin_list(t_flist **head, int *coord_of_sharp, int nbrs_tetra, int min_size)
{
	t_flist	*tmp;
	int		*tmp_int;
	int i;
	int count;
	int j;
	int pos;

	i = 0;
	j = 1;
	pos = 0;
	tmp_int = malloc(sizeof(int) * (nbrs_tetra * 8));
	while (i < nbrs_tetra * 8)
	{
		tmp_int[i] = coord_of_sharp[i];
		i++;
	}
	ft_move_zero_position_all(tmp_int, nbrs_tetra);
	tmp = *head;
	while (*head)
	{
		while (count != 8)
		{
			i = (j - 1) * 8;
			count = 0;
			while (tmp_int[i] == (*head)->crd_sharp[i])
			{
				i++;
				count++;
			}
			if (count == 8)
				pos = i - 8;
			j++;
		}
		j = 0;
		while (j < 8)
		{
			(*head)->crd_sharp[j] = coord_of_sharp[pos];
			tmp_int[pos] = -1;
			pos++;
			j++;
		}
		(*head) = (*head)->next;
	}
	ft_create_map(tmp, min_size);
}
