/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/02 21:09:52 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_sort_a(t_push_swap *ps, t_uint size, t_uint pivot);
static void	_sort_b(t_push_swap *ps, t_uint size, t_uint pivot);

static void	_sort_a_end(t_push_swap *ps, t_uint pivot,
				t_uint size_a, t_uint size_b)
{
	t_uint	i;

	i = 0;
	if (size_a != get_pile(ps, A)->count)
	{
		while (i++ < size_a)
			reverse_rotate(ps, A);
	}
	_sort_a(ps, size_a, pivot + (size_a / 2));
	_sort_b(ps, size_b, pivot - (size_b / 2));
	i = 0;
	while (i++ < size_b)
		push(ps, A);
}

static void	_sort_b_end(t_push_swap *ps, t_uint pivot,
				t_uint size_a, t_uint size_b)
{
	t_uint	i;

	_sort_a(ps, size_a, pivot + (size_a / 2));
	i = 0;
	if (size_b != get_pile(ps, B)->count)
	{
		while (i++ < size_b)
			reverse_rotate(ps, B);
	}
	_sort_b(ps, size_b, pivot - (size_b / 2));
	i = 0;
	while (i++ < size_a)
		push(ps, B);
}

static void	_sort_a(t_push_swap *ps, t_uint size, t_uint pivot)
{
	t_uint	size_a;
	t_uint	size_b;

	if (1 < size)
	{
		size_a = 0;
		size_b = 0;
		while (size_a + size_b < size)
		{
			if (pivot < get_top(ps, A))
			{
				rotate(ps, A);
				size_a++;
			}
			else
			{
				push(ps, B);
				size_b++;
			}
		}
		_sort_a_end(ps, pivot, size_a, size_b);
	}
}

static void	_sort_b(t_push_swap *ps, t_uint size, t_uint pivot)
{
	t_uint	size_a;
	t_uint	size_b;

	if (1 < size)
	{
		size_a = 0;
		size_b = 0;
		while (size_a + size_b < size)
		{
			if (pivot < get_top(ps, B))
			{
				push(ps, A);
				size_a++;
			}
			else
			{
				rotate(ps, B);
				size_b++;
			}
		}
		_sort_b_end(ps, pivot, size_a, size_b);
	}
}

void	quick_sort(t_push_swap *ps)
{
	t_uint	pile_size;

	pile_size = get_pile(ps, A)->count;
	_sort_a(ps, pile_size, pile_size / 2);
}
