/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 21:52:44 by rkina             #+#    #+#             */
/*   Updated: 2019/10/17 21:55:28 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <fcntl.h>

static int		ft_check_dot_diez(char c)
{
	return(c == '.' || c == '#');
}

int		ft_valid_input(int ac, char **argv)
{
	int fd;
	char *line;
	int gnl;
	gnl = 1;
	int count;
	count = 1;
	int j;

	if (ac > 2)
	{
		ft_putendl("error");
		exit (0);
	}
	if (ac == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (gnl > 0)
		{
			gnl = get_next_line(fd, &line);
			if (count % 5 != 0)
			{
				if (ft_strlen(line) != 4)
				{
					ft_putendl("error1");
					free(line);
					exit (0);
				}
				j = 0;
				while (line[j])
				{
					if (!(ft_check_dot_diez(line[j])))
					{
						ft_putendl("error2");
						free(line);
						exit (0);
					}
					j++;
				}
			}
			if ((count % 5 == 0) && line[j] != '\0')
			{
				ft_putendl("error3");
				free(line);
				exit (0);
			}
			printf("%s\n", line);
			printf("count = %d\n", count);
			count++;
		}
		close(fd);
	}
}
