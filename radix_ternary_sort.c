/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_ternary_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/04/14 20:36:00 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_radix_ternary_b(t_push_swap *ps, t_uint nc)
{
	while (get_pile(ps, B)->count)
	{
		if (!((get_top(ps, B) / nc) % 3))
			action(ps, RRB);
		action(ps, PA);
	}
}

static int	_radix_ternary_a(t_push_swap *ps, t_uint nc)
{
	t_uint	all_count;
	t_uint	rank;

	all_count = get_algo(ps)->all_count;
	if (nc < all_count)
	{
		while (all_count--)
		{
			rank = (get_top(ps, A) / nc) % 3;
			if (rank == 2)
				action(ps, RA);
			else
			{
				action(ps, PB);
				if (rank == 0)
					action(ps, RB);
			}
		}
		_radix_ternary_b(ps, nc);
		return (_radix_ternary_a(ps, nc * 3));
	}
	return (EXIT_SUCCESS);
}

void	radix_ternary_sort(t_push_swap *ps)
{
	_radix_ternary_a(ps, 1);
}

/*
0	:	0
1	:	1
2	:	2
10	:	3
11	:	4
12	:	5
20	:	6
21	:	7
22	:	8
100	:	9
*/
