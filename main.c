/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 21:52:44 by rkina             #+#    #+#             */
/*   Updated: 2019/11/03 20:33:49 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int					ft_combinations(int nbrs_tetra)
{
	int				comb;
	int				n;
	int				k;
	int				n_k;

	n = ft_iterative_factorial(nbrs_tetra);
	k = ft_iterative_factorial(2);
	n_k = ft_iterative_factorial(nbrs_tetra - 2);
	comb = n / (k * n_k);
	return (comb);
}

int				main(int ac, char **argv)
{
	int			fd;
	int			count_sharp;
	char		*tetra;
	int			*coord_of_sharp;
	t_flist	*head;
	int			min_size;
	int i;

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
		coord_of_sharp = ft_change_to_coord(tetra, count_sharp);	
		ft_create_flist(count_sharp, coord_of_sharp, &head);
		min_size = ft_count_min_s(count_sharp / 4);
		coord_of_sharp = ft_move_zero_position_all(coord_of_sharp, count_sharp);
		ft_all_overl(&head, coord_of_sharp, min_size - 1, count_sharp / 4);
		i = 0;
		printf("After solve\n");
		while (i < count_sharp * 2)
		{
			printf("%d", coord_of_sharp[i]);
			if ((i + 1) % 8 == 0)
				printf("|");
			i++;
			printf(" ");
		}
	}
}
