/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   high_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/01/21 20:58:11 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_tier(t_push_swap *ps, t_uint max)
{
	t_uint	pile_count;
	t_uint	top;
	t_uint	i;

	pile_count = get_pile(ps, A)->count;
	if (3 < pile_count)
	{
		i = 0;
		while (i < pile_count)
		{
			top = get_top(ps, A);
			if (max - pile_count / 3 < top || max - 3 <= top)
				action(ps, RA);
			else
			{
				action(ps, PB);
				if (top < max - 2 * pile_count / 3)
					action(ps, RB);
			}
			i++;
		}
		_tier(ps, max);
	}
}

void	high_sort(t_push_swap *ps)
{
	_tier(ps, get_pile(ps, A)->count);
	tiny_sort(ps);
	best_sort(ps);
}
