/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/10 22:35:46 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_pile *pile)
{
	t_list	*buf;

	if (1 < pile->a_count)
	{
		buf = pile->a;
		pile->a = pile->a->next;
		buf->next = pile->a->next;
		pile->a->next = buf;
	}
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	swap_b(t_pile *pile)
{
	t_list	*buf;

	if (1 < pile->b_count)
	{
		buf = pile->b;
		pile->b = pile->b->next;
		buf->next = pile->b->next;
		pile->b->next = buf;
	}
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	swap_swap(t_pile *pile)
{
	t_list	*buf;

	if (1 < pile->a_count)
	{
		buf = pile->a;
		pile->a = pile->a->next;
		buf->next = pile->a->next;
		pile->a->next = buf;
	}
	if (1 < pile->b_count)
	{
		buf = pile->b;
		pile->b = pile->b->next;
		buf->next = pile->b->next;
		pile->b->next = buf;
	}
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}
