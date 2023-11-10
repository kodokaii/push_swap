/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/10 22:44:16 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_pile *pile)
{
	t_list	*buf;

	if (1 < pile->a_count)
	{
		buf = pile->a->next;
		ft_lstlast(pile->a)->next = pile->a;
		pile->a->next = NULL;
		pile->a = buf;
	}
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rotate_b(t_pile *pile)
{
	t_list	*buf;

	if (1 < pile->b_count)
	{
		buf = pile->b->next;
		ft_lstlast(pile->b)->next = pile->b;
		pile->b->next = NULL;
		pile->b = buf;
	}
	ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rotate_rotate(t_pile *pile)
{
	t_list	*buf;

	if (1 < pile->a_count)
	{
		buf = pile->a->next;
		ft_lstlast(pile->a)->next = pile->a;
		pile->a->next = NULL;
		pile->a = buf;
	}
	if (1 < pile->b_count)
	{
		buf = pile->b->next;
		ft_lstlast(pile->b)->next = pile->b;
		pile->b->next = NULL;
		pile->b = buf;
	}
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}
