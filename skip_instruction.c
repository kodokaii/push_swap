/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/06 15:21:28 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_instruction(t_uint instruction, t_uint count, ...)
{
	va_list	arg;
	t_uint	i;

	i = 0;
	va_start(arg, count);
	while (i < count && va_arg(arg, t_uint) != instruction)
		i++;
	va_end(arg);
	return (i != count);
}

t_list	*skip_instruction(t_push_swap *ps, t_uint instruction)
{
	t_list	*current;
	t_algo	*algo;

	algo = get_algo(ps);
	current = algo->instruction;
	while (current && *((t_uint *)current->data) == instruction)
		current = current->next;
	return (current);
}

t_list	**skip_instruction_a(t_push_swap *ps)
{
	t_list	**current;
	t_algo	*algo;

	algo = get_algo(ps);
	current = &algo->instruction;
	while (*current
		&& is_instruction(*((t_uint *)(*current)->data), 3, SA, RA, RRA))
		current = &(*current)->next;
	return (current);
}

t_list	**skip_instruction_b(t_push_swap *ps)
{
	t_list	**current;
	t_algo	*algo;

	algo = get_algo(ps);
	current = &algo->instruction;
	while (*current
		&& is_instruction(*((t_uint *)(*current)->data), 3, SB, RB, RRB))
		current = &(*current)->next;
	return (current);
}
