/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:53:57 by npetrell          #+#    #+#             */
/*   Updated: 2019/11/07 20:48:13 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void			ft_print_map(int size_map, char map[size_map][size_map])
{
	int			x;
	int			y;

	x = -1;
	while (++x < size_map)
	{
		y = -1;
		while (++y < size_map)
			write(1, &map[x][y], 1);
		write(1, "\n", 1);
	}
}

void			ft_create_map(t_flist *head, int size_map)
{
	char		map[size_map][size_map];
	int			i;
	int			x;
	int			y;

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

int				ft_find_max_size(int *coord_of_sharp, int nbrs_tetra)
{
	int			i;
	int			max_size;

	i = 1;
	max_size = coord_of_sharp[0];
	while (i < nbrs_tetra * 8)
	{
		if (max_size < coord_of_sharp[i])
			max_size = coord_of_sharp[i];
		i++;
	}
	return (max_size);
}

int				ft_find_position(t_flist **head, int *tmp_int)
{
	int			i;
	int			k;
	int			count;
	int			j;
	int			pos;

	i = 0;
	count = 0;
	j = 1;
	while (count != 8)
	{
		i = (j - 1) * 8;
		count = 0;
		k = 0;
		while (i < j * 8)
		{
			if (tmp_int[i++] != (*head)->crd_sharp[k++])
				break ;
			count++;
		}
		if (count == 8)
			pos = (j - 1) * 8;
		j++;
	}
	return (pos);
}

void			ft_add_to_fin_list(t_flist **head,
int *coord_of_sharp, int nbrs_tetra)
{
	t_flist		*tmp;
	int			*tmp_int;
	int			i;
	int			pos;

	i = -1;
	tmp_int = (int*)malloc(sizeof(int) * (nbrs_tetra * 8));
	while (++i < nbrs_tetra * 8)
		tmp_int[i] = coord_of_sharp[i];
	tmp_int = ft_move_zero_position_all(tmp_int, nbrs_tetra * 8);
	tmp = *head;
	while (*head)
	{
		pos = ft_find_position(head, tmp_int);
		i = -1;
		while (++i < 8)
		{
			(*head)->crd_sharp[i] = coord_of_sharp[pos];
			tmp_int[pos++] = -1;
		}
		(*head) = (*head)->next;
	}
	pos = ft_find_max_size(coord_of_sharp, nbrs_tetra);
	free(tmp_int);
	ft_create_map(tmp, pos + 1);
	ft_del_list(head);
}
