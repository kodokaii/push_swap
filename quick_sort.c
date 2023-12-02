/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/02 02:58:07 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_sort_a(t_pile *pile, t_uint size, t_uint pivot);

int	_sort_a_end(t_pile *pile, t_uint pivot,
				t_uint size_a, t_uint size_b)
{
	t_uint	i;

	i = 0;
	if (size_a != pile->a_count)
		while (i++ < size_a)
			reverse_rotate_a(pile);
	if (_sort_a(pile, size_a, pivot + (size_a / 2)))
		return (EXIT_FAILURE);
	i = 0;
	while (i++ < size_b)
		push_a(pile);
	if (_sort_a(pile, size_b, pivot - (size_b / 2)))
		return (EXIT_FAILURE);
	return (errno == ENOMEM);
}

static int	_sort_a(t_pile *pile, t_uint size, t_uint pivot)
{
	t_uint	size_a;
	t_uint	size_b;
	t_uint	current;

	if (1 < size)
	{
		size_a = 0;
		size_b = 0;
		while (size_a + size_b < size)
		{
			current = *(t_uint *)pile->a->data;
			if (pivot < current)
			{
				rotate_a(pile);
				size_a++;
			}
			else
			{
				push_b(pile);
				size_b++;
			}
		}
		return (_sort_a_end(pile, pivot, size_a, size_b));
	}
	return (EXIT_SUCCESS);
}

int	quick_sort(t_pile *pile, t_uint *tab, t_uint tab_size)
{
	if (pile_init(pile, tab, tab_size))
		return (EXIT_FAILURE);
	return (_sort_a(pile, pile->a_count, pile->a_count / 2));
}
