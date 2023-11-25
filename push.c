/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/25 17:19:20 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_pile *pile)
{
	t_list	*buf;

	if (pile->b_count)
	{
		buf = pile->b->next;
		ft_lstadd_front(&pile->a, pile->b);
		pile->b = buf;
		pile->b_count--;
		pile->a_count++;
		ft_putstr_fd("pa\n", STDOUT_FILENO);
	}
}

void	push_b(t_pile *pile)
{
	t_list	*buf;

	if (pile->a_count)
	{
		buf = pile->a->next;
		ft_lstadd_front(&pile->b, pile->a);
		pile->a = buf;
		pile->a_count--;
		pile->b_count++;
		ft_putstr_fd("pb\n", STDOUT_FILENO);
	}
}
