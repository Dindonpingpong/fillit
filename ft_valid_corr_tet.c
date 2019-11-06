/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_corr_tet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 21:56:11 by rkina             #+#    #+#             */
/*   Updated: 2019/11/06 18:19:34 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_count_neigh(int i, char *s)
{
	int		n_nghrs;

	n_nghrs = 0;
	if ((s[i + 1] == '#') && (i + 1 < 16))
		n_nghrs++;
	if ((s[i - 1] == '#') && (i - 1 >= 0))
		n_nghrs++;
	if ((s[i + 4] == '#') && (i + 4 < 16))
		n_nghrs++;
	if ((s[i - 4] == '#') && (i - 4 >= 0))
		n_nghrs++;
	return (n_nghrs);
}

void		ft_valid_corr_tet(char *str)
{
	int		i;
	int		sum_nghrs;

	i = 0;
	sum_nghrs = 0;
	while (str[i])
	{
		if (str[i] == '#')
			sum_nghrs += ft_count_neigh(i, str);
		i++;
	}
	if (sum_nghrs == 6 || sum_nghrs == 8)
		return ;
	ft_error_output();
}

char		*ft_valid_tetra(const int fd)
{
	int		i;
	char	*tmp1;
	char	*line;
	char	*tetra;
	char	*tmp;

	i = 0;
	tetra = ft_strnew(1);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = tetra;
		tetra = ft_strjoin(tetra, line);
	}
	while (tetra[i])
	{
		tmp1 = ft_strsub(&tetra[i], 0, 16);
		i += 16;
		ft_valid_corr_tet(tmp1);
	}
	return (tetra);
}
