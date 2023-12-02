/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/02 00:58:48 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(t_pile *pile)
{
	t_list	*tmp;

	if (1 < pile->a_count)
	{
		tmp = pile->a->next;
		ft_lstlast(pile->a)->next = pile->a;
		pile->a->next = NULL;
		pile->a = tmp;
		return (add_instruction(pile, RA));
	}
	return (EXIT_SUCCESS);
}

int	rotate_b(t_pile *pile)
{
	t_list	*tmp;

	if (1 < pile->b_count)
	{
		tmp = pile->b->next;
		ft_lstlast(pile->b)->next = pile->b;
		pile->b->next = NULL;
		pile->b = tmp;
		return (add_instruction(pile, RB));
	}
	return (EXIT_SUCCESS);
}

int	rotate_rotate(t_pile *pile)
{
	t_list	*tmp;

	if (1 < pile->a_count)
	{
		tmp = pile->a->next;
		ft_lstlast(pile->a)->next = pile->a;
		pile->a->next = NULL;
		pile->a = tmp;
	}
	if (1 < pile->b_count)
	{
		tmp = pile->b->next;
		ft_lstlast(pile->b)->next = pile->b;
		pile->b->next = NULL;
		pile->b = tmp;
	}
	if (1 < pile->a_count && 1 < pile->b_count)
		return (add_instruction(pile, RR));
	return (EXIT_SUCCESS);
}
