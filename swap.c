/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/02 00:59:45 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_pile *pile)
{
	t_list	*tmp;

	if (1 < pile->a_count)
	{
		tmp = pile->a;
		pile->a = pile->a->next;
		tmp->next = pile->a->next;
		pile->a->next = tmp;
		return (add_instruction(pile, SA));
	}
	return (EXIT_SUCCESS);
}

int	swap_b(t_pile *pile)
{
	t_list	*tmp;

	if (1 < pile->b_count)
	{
		tmp = pile->b;
		pile->b = pile->b->next;
		tmp->next = pile->b->next;
		pile->b->next = tmp;
		return (add_instruction(pile, SB));
	}
	return (EXIT_SUCCESS);
}

int	swap_swap(t_pile *pile)
{
	t_list	*tmp;

	if (1 < pile->a_count)
	{
		tmp = pile->a;
		pile->a = pile->a->next;
		tmp->next = pile->a->next;
		pile->a->next = tmp;
	}
	if (1 < pile->b_count)
	{
		tmp = pile->b;
		pile->b = pile->b->next;
		tmp->next = pile->b->next;
		pile->b->next = tmp;
	}
	if (1 < pile->a_count || 1 < pile->b_count)
		return (add_instruction(pile, SS));
	return (EXIT_SUCCESS);
}
