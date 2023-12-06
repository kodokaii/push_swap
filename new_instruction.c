/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/06 15:35:07 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_uint	_remove_instruction(t_push_swap *ps, t_uint instruction)
{
	t_list	**current;
	t_algo	*algo;

	algo = get_algo(ps);
	if (algo->instruction_count)
	{
		current = &algo->instruction;
		if (is_instruction(instruction, 3, SA, RA, RRA))
			current = skip_instruction_b(ps);
		if (is_instruction(instruction, 3, SB, RB, RRB))
			current = skip_instruction_a(ps);
		if (inverse_instruction(instruction) == *((t_uint *)(*current)->data))
		{
			delete_next_instruction(ps, current);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}

static t_bool	_toggle_rotate(t_push_swap *ps, t_uint instruction)
{
	t_uint	instruction_count;
	t_uint	instruction_inverse;
	t_pile	*pile;
	t_uint	i;

	pile = NULL;
	if (is_instruction(instruction, 2, RA, RRA))
		pile = get_pile(ps, A);
	if (is_instruction(instruction, 2, RB, RRB))
		pile = get_pile(ps, B);
	instruction_count = count_instruction(ps, instruction);
	if (pile && pile->count / 2 <= instruction_count)
	{
		i = 0;
		instruction_inverse = inverse_instruction(instruction);
		while (i++ < instruction_count)
			delete_instruction(ps);
		while (i++ < pile->count)
			new_instruction(ps, instruction_inverse);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

static t_bool	_fact_instruction(t_push_swap *ps, t_uint instruction)
{
	t_list	*current;

	current = NULL;
	if (get_algo(ps)->instruction_count)
	{
		if (is_instruction(instruction, 2, SA, SB))
			current = skip_instruction(ps, SS);
		if (is_instruction(instruction, 2, RA, RB))
			current = skip_instruction(ps, RR);
		if (is_instruction(instruction, 2, RRA, RRB))
			current = skip_instruction(ps, RRR);
		if ((instruction == SA && *((t_uint *)current->data) == SB)
			|| (instruction == SB && *((t_uint *)current->data) == SA))
			return (current->data = get_instruction(SS), EXIT_SUCCESS);
		if ((instruction == RA && *((t_uint *)current->data) == RB)
			|| (instruction == RB && *((t_uint *)current->data) == RA))
			return (current->data = get_instruction(RR), EXIT_SUCCESS);
		if ((instruction == RRA && *((t_uint *)current->data) == RRB)
			|| (instruction == RRB && *((t_uint *)current->data) == RRA))
			return (current->data = get_instruction(RRR), EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

void	new_instruction(t_push_swap *ps, t_uint instruction)
{
	if (_remove_instruction(ps, instruction)
		&& _toggle_rotate(ps, instruction)
		&& _fact_instruction(ps, instruction))
		add_instruction(ps, instruction);
}
