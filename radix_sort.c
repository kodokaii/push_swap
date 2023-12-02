/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/02 01:29:00 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_radix(t_pile *pile, t_uint bit)
{
	t_uint	i;

	i = 0;
	if ((1 << bit) <= pile->all_count)
	{
		while (i < pile->all_count)
		{
			if (*(t_uint *)pile->a->data & (1 << bit))
				rotate_a(pile);
			else
				push_b(pile);
			i++;
		}
		while (pile->b_count)
			push_a(pile);
		return (_radix(pile, bit + 1));
	}
	return (errno == ENOMEM);
}

int	radix_sort(t_pile *pile, t_uint *tab, t_uint tab_size)
{
	if (pile_init(pile, tab, tab_size))
		return (EXIT_FAILURE);
	return (_radix(pile, 0));
}
