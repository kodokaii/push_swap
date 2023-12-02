/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/02 00:58:28 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_pile *pile)
{
	t_list	*tmp;

	if (pile->b_count)
	{
		tmp = pile->b->next;
		ft_lstadd_front(&pile->a, pile->b);
		pile->b = tmp;
		pile->b_count--;
		pile->a_count++;
		return (add_instruction(pile, PA));
	}
	return (EXIT_SUCCESS);
}

int	push_b(t_pile *pile)
{
	t_list	*tmp;

	if (pile->a_count)
	{
		tmp = pile->a->next;
		ft_lstadd_front(&pile->b, pile->a);
		pile->a = tmp;
		pile->a_count--;
		pile->b_count++;
		return (add_instruction(pile, PB));
	}
	return (EXIT_SUCCESS);
}
