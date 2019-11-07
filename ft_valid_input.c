/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:05:56 by rkina             #+#    #+#             */
/*   Updated: 2019/11/07 19:49:19 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_valid_input(const int fd)
{
	char	*line;
	int		count;
	int		j;
	int		i;

	count = 0;
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (++count % 5 != 0)
		{
			ft_strlen(line) != 4 ? ft_error_output() : line;
			j = -1;
			while (line[++j])
			{
				line[j] == '.' || line[j] == '#' ? line[j] : ft_error_output();
				line[j] == '#' ? i++ : i;
			}
		}
	//	(count % 5 == 0) && line[j] != '\0' ? ft_error_output() : line[j]; // there is a mistake
		free(line);
	}
	i % 4 != 0 ? ft_error_output() : i;
	count + 1 > 130 ? ft_error_output() : count;
	return (i);
}
