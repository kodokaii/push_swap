/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/10 22:08:21 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_swap_exit(int error, t_pile *pile)
{
	ft_lstclear(&pile->a, NULL);
	ft_lstclear(&pile->b, NULL);
	return (error);
}

static int	init_pile(int *tab, int tab_size, t_pile *pile)
{
	t_list	*new;

	pile->all_count = tab_size;
	pile->a_count = tab_size;
	pile->b_count = 0;
	pile->a = NULL;
	pile->b = NULL;
	while (--tab_size)
	{
		new = ft_lstnew(tab + tab_size);
		if (!new)
			return (EXIT_FAILURE);
		ft_lstadd_front(&pile->a, new);
	}
	return (EXIT_SUCCESS);
}

int	push_swap(int *tab, int tab_size)
{
	t_pile	pile;

	if (init_pile(tab, tab_size, &pile))
		return (push_swap_exit(EXIT_FAILURE, &pile));
	return (push_swap_exit(EXIT_SUCCESS, &pile));
}
