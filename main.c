/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 21:52:44 by rkina             #+#    #+#             */
/*   Updated: 2019/11/06 18:26:26 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int				main(int ac, char **argv)
{
	int			fd;
	int			count_sharp;
	char		*tetra;
	int			*coords_of_sharp;
	t_flist		*head;
	int			min_size;

	head = NULL;
	if (ac != 2)
		ft_error_output();
	if (ac == 2)
	{
		fd = open(argv[1], O_RDONLY);
		count_sharp = ft_valid_input(fd);
		close(fd);
		fd = open(argv[1], O_RDONLY);
		tetra = ft_valid_tetra(fd);
		close(fd);
		coords_of_sharp = ft_change_to_coord(tetra, count_sharp);
		ft_create_flist(count_sharp, coords_of_sharp, &head);
		min_size = ft_count_min_s(count_sharp / 4);
		coords_of_sharp = ft_move_zero_position_all(coords_of_sharp, count_sharp);
		ft_fillit(&head, coords_of_sharp, min_size, count_sharp / 4);
	}
}
