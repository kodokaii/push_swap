/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/06 02:33:13 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_radix_a(t_push_swap *ps, t_uint bit)
{
	t_uint	all_count;

	all_count = get_algo(ps)->all_count;
	if ((1 << bit) < all_count)
	{
		while (all_count--)
		{
			if (get_top(ps, A) & (1 << bit))
				action(ps, RA);
			else
				action(ps, PB);
		}
		while (get_pile(ps, B)->count)
			action(ps, PA);
		return (_radix_a(ps, bit + 1));
	}
	return (EXIT_SUCCESS);
}

void	radix_sort(t_push_swap *ps)
{
	_radix_a(ps, 0);
}
