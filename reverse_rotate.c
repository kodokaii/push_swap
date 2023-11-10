/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/10 22:48:30 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_pile *pile)
{
	t_list	*buf;

	if (1 < pile->a_count)
	{
		buf = pile->a;
		while (buf->next->next)
			buf = buf->next;
		buf->next->next = pile->a;
		pile->a = buf->next->next;
		buf->next = NULL;
	}
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	reverse_rotate_b(t_pile *pile)
{
	t_list	*buf;

	if (1 < pile->b_count)
	{
		buf = pile->b;
		while (buf->next->next)
			buf = buf->next;
		buf->next->next = pile->b;
		pile->b = buf->next->next;
		buf->next = NULL;
	}
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	reverse_rotate_rotate(t_pile *pile)
{
	t_list	*buf;

	if (1 < pile->a_count)
	{
		buf = pile->a;
		while (buf->next->next)
			buf = buf->next;
		buf->next->next = pile->a;
		pile->a = buf->next->next;
		buf->next = NULL;
	}
	if (1 < pile->b_count)
	{
		buf = pile->b;
		while (buf->next->next)
			buf = buf->next;
		buf->next->next = pile->b;
		pile->b = buf->next->next;
		buf->next = NULL;
	}
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
