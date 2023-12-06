/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/06 00:25:15 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_merge_sort_a(t_push_swap *ps, t_uint size);
static void	_merge_sort_b(t_push_swap *ps, t_uint size);

static void	_merge_a(t_push_swap *ps, t_uint size_a, t_uint size_b)
{
	t_uint	size;

	size = size_a + size_b;
	while (size_b)
	{
		if (!size_a || get_top(ps, B) < get_top(ps, A))
		{
			action(ps, PA);
			size_a++;
			size_b--;
		}
		else
		{
			action(ps, RA);
			size_a--;
		}
	}
	while (size_a++ < size)
		action(ps, RRA);
}

static void	_merge_b(t_push_swap *ps, t_uint size_a, t_uint size_b)
{
	t_uint	size;

	size = size_a + size_b;
	while (size_a)
	{
		if (!size_b || get_top(ps, A) < get_top(ps, B))
		{
			action(ps, PB);
			size_b++;
			size_a--;
		}
		else
		{
			action(ps, RB);
			size_b--;
		}
	}
	while (size_b++ < size)
		action(ps, RRB);
}

static void	_merge_sort_b(t_push_swap *ps, t_uint size_b)
{
	t_uint	size_a;

	if (1 < size_b)
	{
		size_a = 0;
		while (size_a < size_b)
		{
			action(ps, PA);
			size_a++;
			size_b--;
		}
		_merge_sort_b(ps, size_b);
		_merge_sort_a(ps, size_a);
		_merge_b(ps, size_a, size_b);
	}
}

static void	_merge_sort_a(t_push_swap *ps, t_uint size_a)
{
	t_uint	size_b;

	if (1 < size_a)
	{
		size_b = 0;
		while (size_b < size_a)
		{
			action(ps, PB);
			size_b++;
			size_a--;
		}
		_merge_sort_b(ps, size_b);
		_merge_sort_a(ps, size_a);
		_merge_a(ps, size_a, size_b);
	}
}

void	merge_sort(t_push_swap *ps)
{
	t_uint	pile_size;

	pile_size = get_pile(ps, A)->count;
	_merge_sort_a(ps, pile_size);
}
