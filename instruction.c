/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/02 21:20:30 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_push_swap *ps, t_uint pile_index)
{
	t_pile	*pile;
	t_list	*tmp;

	pile = get_pile(ps, pile_index);
	if (2 <= pile->count)
	{
		tmp = pile->lst;
		pile->lst = pile->lst->next;
		tmp->next = pile->lst->next;
		pile->lst->next = tmp;
		add_instruction(ps, SA + pile_index);
	}
}

void	push(t_push_swap *ps, t_uint pile_index)
{
	t_pile	*pile_from;
	t_pile	*pile_to;
	t_list	*tmp;

	pile_from = get_pile(ps, (pile_index + 1) % PILE_COUNT);
	pile_to = get_pile(ps, pile_index);
	if (pile_from->count)
	{
		tmp = pile_from->lst->next;
		ft_lstadd_front(&pile_to->lst, pile_from->lst);
		pile_from->lst = tmp;
		pile_from->count--;
		pile_to->count++;
		add_instruction(ps, PA + pile_index);
	}
}

void	rotate(t_push_swap *ps, t_uint pile_index)
{
	t_pile	*pile;
	t_list	*tmp;

	pile = get_pile(ps, pile_index);
	if (2 <= pile->count)
	{
		tmp = pile->lst->next;
		ft_lstlast(pile->lst)->next = pile->lst;
		pile->lst->next = NULL;
		pile->lst = tmp;
		add_instruction(ps, RA + pile_index);
	}
}

void	reverse_rotate(t_push_swap *ps, t_uint pile_index)
{
	t_pile	*pile;
	t_list	**end;

	pile = get_pile(ps, pile_index);
	if (2 <= pile->count)
	{
		end = &(pile->lst->next);
		while ((*end)->next)
			end = &(*end)->next;
		(*end)->next = pile->lst;
		pile->lst = *end;
		*end = NULL;
		add_instruction(ps, RRA + pile_index);
	}
}
