/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/25 17:11:37 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_pile *pile)
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
		ft_putstr_fd("rra\n", STDOUT_FILENO);
	}
}

void	reverse_rotate_b(t_pile *pile)
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
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
	}
}

void	reverse_rotate_rotate(t_pile *pile)
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
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
