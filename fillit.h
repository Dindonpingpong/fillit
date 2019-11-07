/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:59:03 by rkina             #+#    #+#             */
/*   Updated: 2019/11/07 20:12:45 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <fcntl.h>

typedef struct				s_flist {
	int						crd_sharp[8];
	char					name;
	struct s_flist			*prev;
	struct s_flist			*next;
}							t_flist;

int							ft_valid_input(const int fd);
char						*ft_valid_tetra(const int fd);
void						ft_valid_corr_tet(char *str);
t_flist						*create_flist(t_flist *head, char name_tetra);
void						ft_create_flist(int count_sharp,
int *coord_of_sharp, t_flist **head);
int							ft_count_min_s(int tets);
int							*ft_change_to_coord(char *tetra, int count_sharp);
void						ft_move(int *coord_of_tet, int nbr_tet, char x_y);
int							ft_overlay(int *coords, int nbr_tet);
void						ft_fillit(t_flist **head, int *coord_of_sharp,
int min_size, int nbrs_tetra);
int							*ft_move_zero_position(int *coord, int nbr_tet);
int							*ft_move_zero_position_all(int *coord, int len);
void						ft_create_map(t_flist *head, int size_map);
void						ft_add_to_fin_list(t_flist **head,
int *coord_of_sharp, int nbrs_tetra);
int							ft_check_over_map(int *crds, int nbrs_tet,
int min_size, char x_y);
int							*ft_move_zero_position_x(int *coord, int nbr_tet);
void         				ft_del_list(t_flist **head);
void						dltnode(t_flist **head, t_flist *del);
#endif
