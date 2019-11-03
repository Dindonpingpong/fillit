/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:53:57 by npetrell          #+#    #+#             */
/*   Updated: 2019/11/01 20:41:37 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void       ft_print_map(int size_map, char map[size_map][size_map])
{
    int     x;
    int     y;

    x = -1;
    while (++x < size_map)
    {
        y = -1;
        while (++y < size_map)
            write(1, &map[x][y], 1);
        write(1, "\n", 1);
    }
}

void       ft_create_map(t_flist  *head, int size_map)
{
    char   map[size_map][size_map];
    int    i;
    int    x;
    int    y;

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

void       ft_add_to_fin_list(t_flist **head, int *coord_of_sharp, int nbrs_tetra, int min_size)//не правильно работает проверка на соответствие с фигурой
{
    int     i;
    int     j;
    int     remainder;
    //int     remainder2;
    t_flist *tmp;
    int     count;

    tmp = *head;
    while (*head)
    {
        i = 0;
        while (i < nbrs_tetra * 8)
        {
            j = 0;
            count = 0;
            while (j < 8)
            {
                remainder = coord_of_sharp[i] - (*head)->crd_sharp[j];
                //remainder2 = coord_of_sharp[i + 1] - (*head)->crd_sharp[j + 1];
                if (remainder == (coord_of_sharp[i + 2] - (*head)->crd_sharp[j + 2]))
                {
                    count++;
                }
                i++;
                j++;
            }
            if (count == 4)
            {
                j = 0;
                while (j < 8)
                {
                    (*head)->crd_sharp[j] = coord_of_sharp[i];
                    coord_of_sharp[i] = 0;
                    j++;
                    i++;
                }
                break ;
            }
            i++;
        }
        (*head) = (*head)->next;
    }
    ft_create_map(tmp, min_size); // size_map второй аргумент
}
