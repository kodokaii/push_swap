/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/04 05:07:05 by nlaerema         ###   ########.fr       */
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
			push(ps, A);
			size_a++;
			size_b--;
		}
		else
		{
			rotate(ps, A);
			size_a--;
		}
	}
	if (size - size_a < get_pile(ps, A)->count / 2)
	{
		while (size_a++ < size)
			reverse_rotate(ps, A);
	}
	else
		while (size_a--)
			rotate(ps, A);
}

static void	_merge_b(t_push_swap *ps, t_uint size_a, t_uint size_b)
{
	t_uint	size;

	size = size_a + size_b;
	while (size_a)
	{
		if (!size_b || get_top(ps, A) < get_top(ps, B))
		{
			push(ps, B);
			size_b++;
			size_a--;
		}
		else
		{
			rotate(ps, B);
			size_b--;
		}
	}
	if (size - size_b < get_pile(ps, B)->count / 2)
	{
		while (size_b++ < size)
			reverse_rotate(ps, B);
	}
	else
		while (size_b--)
			rotate(ps, B);
}

static void	_merge_sort_b(t_push_swap *ps, t_uint size_b)
{
	t_uint	size_a;

	if (1 < size_b)
	{
		size_a = 0;
		while (size_a < size_b)
		{
			push(ps, A);
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
			push(ps, B);
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
