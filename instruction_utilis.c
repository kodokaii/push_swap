/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_utilis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/05 23:58:42 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_uint	inverse_instruction(t_uint instruction)
{
	static t_uint	inverse_instruction_tab[INSTRUCTION_COUNT]
		= {SA, SB, SS, PB, PA, RRA, RRB, RRR, RA, RB, RR};

	return (inverse_instruction_tab[instruction]);
}

t_uint	count_instruction(t_push_swap *ps, t_uint instruction)
{
	t_list	*current;
	t_uint	count;
	t_algo	*algo;

	count = 0;
	algo = get_algo(ps);
	current = algo->instruction;
	while (current && *((t_uint *)current->data) == instruction)
	{
		current = current->next;
		count++;
	}
	return (count);
}

void	delete_instruction(t_push_swap *ps)
{
	t_list	*tmp;
	t_algo	*algo;

	algo = get_algo(ps);
	if (algo->instruction_count)
	{
		tmp = algo->instruction->next;
		free(algo->instruction);
		algo->instruction = tmp;
		algo->instruction_count--;
	}
}

void	add_instruction(t_push_swap *ps, t_uint instruction)
{
	t_list			*new;
	t_algo			*algo;

	algo = get_algo(ps);
	new = ft_lstnew(get_instruction(instruction));
	if (!new)
		push_swap_end(ps, ERRLOC, EXIT_FAILURE);
	ft_lstadd_front(&algo->instruction, new);
	algo->instruction_count++;
}
