/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/02 01:54:36 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pile_init(t_pile *pile, t_uint *tab, t_uint tab_size)
{
	t_list	*new;

	pile->all_count = tab_size;
	pile->a_count = tab_size;
	pile->b_count = 0;
	pile->a = NULL;
	pile->b = NULL;
	pile->instruction_count = 0;
	pile->instruction = NULL;
	while (tab_size--)
	{
		new = ft_lstnew(tab + tab_size);
		if (!new)
			return (EXIT_FAILURE);
		ft_lstadd_front(&pile->a, new);
	}
	return (EXIT_SUCCESS);
}

t_uint	sort_count(t_pile *pile)
{
	t_list	*current;
	t_uint	res;
	t_uint	i;

	i = 1;
	res = 0;
	current = pile->a;
	while (i <= pile->a_count)
	{
		if (i == *(t_uint *)current->data)
			res++;
		current = current->next;
		i++;
	}
	return (res);
}
