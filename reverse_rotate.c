/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/02 00:59:11 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate_a(t_pile *pile)
{
	t_list	**end;

	if (1 < pile->a_count)
	{
		end = &(pile->a->next);
		while ((*end)->next)
			end = &(*end)->next;
		(*end)->next = pile->a;
		pile->a = *end;
		*end = NULL;
		return (add_instruction(pile, RRA));
	}
	return (EXIT_SUCCESS);
}

int	reverse_rotate_b(t_pile *pile)
{
	t_list	**end;

	if (1 < pile->b_count)
	{
		end = &(pile->b->next);
		while ((*end)->next)
			end = &(*end)->next;
		(*end)->next = pile->b;
		pile->b = *end;
		*end = NULL;
		return (add_instruction(pile, RRB));
	}
	return (EXIT_SUCCESS);
}

int	reverse_rotate_rotate(t_pile *pile)
{
	t_list	**end;

	if (1 < pile->a_count)
	{
		end = &(pile->a->next);
		while ((*end)->next)
			end = &(*end)->next;
		(*end)->next = pile->a;
		pile->a = *end;
		*end = NULL;
	}
	if (1 < pile->b_count)
	{
		end = &(pile->b->next);
		while ((*end)->next)
			end = &(*end)->next;
		(*end)->next = pile->b;
		pile->b = *end;
		*end = NULL;
	}
	if (1 < pile->a_count || 1 < pile->b_count)
		return (add_instruction(pile, RRR));
	return (EXIT_SUCCESS);
}
