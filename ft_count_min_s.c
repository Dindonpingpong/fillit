/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_min_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:58:25 by rkina             #+#    #+#             */
/*   Updated: 2019/10/25 16:48:42 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_count_min_s(int tets)
{
	if (tets == 2)
		return (3);
	if (tets >= 3 && tets <= 4)
		return (4);
	if (tets >= 5 && tets <= 6)
		return (5);
	if (tets >= 7 && tets <= 8)
		return (6);
	if (tets >= 9 && tets <= 10)
		return (7);
	if (tets >= 11 && tets <= 16)
		return (8);
	if (tets >= 17 && tets <= 18)
		return (9);
	if (tets >= 19 && tets <= 20)
		return (10);
	if (tets >= 21 && tets <= 25)
		return (11);
	if (tets == 26)
		return (12);
	return (2);
}
