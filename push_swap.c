/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/27 14:25:01 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_end(int error, t_pile *pile)
{
	ft_lstclear(&pile->a, NULL);
	ft_lstclear(&pile->b, NULL);
	return (error);
}

static int	_init(int *tab, int tab_size, t_pile *pile)
{
	t_list	*new;

	pile->all_count = tab_size;
	pile->a_count = tab_size;
	pile->b_count = 0;
	pile->a = NULL;
	pile->b = NULL;
	while (tab_size--)
	{
		new = ft_lstnew(tab + tab_size);
		if (!new)
			return (EXIT_FAILURE);
		ft_lstadd_front(&pile->a, new);
	}
	return (EXIT_SUCCESS);
}

void	ft_radix_sort(t_pile *pile, t_uint bit)
{
	int	i;

	i = 0;
	if ((1 << bit) < pile->all_count)
	{
		while (i < pile->all_count)
		{
			if (*(int *)pile->a->data & (1 << bit))
				rotate_a(pile);
			else
				push_b(pile);
			i++;
		}
		while (pile->b_count)
			push_a(pile);
		ft_radix_sort(pile, bit + 1);
	}
}

int	push_swap(int *tab, int tab_size)
{
	t_pile	pile;

	if (_init(tab, tab_size, &pile))
		return (_end(EXIT_FAILURE, &pile));
	ft_radix_sort(&pile, 0);
	return (_end(EXIT_SUCCESS, &pile));
}
