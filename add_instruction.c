/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/04 03:59:04 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	_is_useless_instruction(t_uint instruction,
		t_uint last_instruction)
{
	return ((instruction == SA && last_instruction == SA)
		|| (instruction == SB && last_instruction == SB)
		|| (instruction == SS && last_instruction == SS)
		|| (instruction == PA && last_instruction == PB)
		|| (instruction == PB && last_instruction == PA)
		|| (instruction == RA && last_instruction == RRA)
		|| (instruction == RB && last_instruction == RRB)
		|| (instruction == RR && last_instruction == RRR)
		|| (instruction == RRA && last_instruction == RA)
		|| (instruction == RRB && last_instruction == RB)
		|| (instruction == RRR && last_instruction == RR));
}

static t_list	*_skip(t_algo *algo, t_uint instruction)
{
	t_list	*current;

	current = algo->instruction;
	while (current && *((t_uint *)current->data) == instruction)
		current = current->next;
	return (current);
}

static t_uint	_remove_instruction(t_algo *algo, t_uint instruction)
{
	t_list	*tmp;

	if (algo->instruction_count)
	{
		if (_is_useless_instruction(instruction,
				*((t_uint *)algo->instruction->data)))
		{
			tmp = algo->instruction->next;
			free(algo->instruction);
			algo->instruction = tmp;
			algo->instruction_count--;
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}

static t_bool	_fact_instruction(t_algo *algo,
		t_uint instruction, t_uint *instruction_tab)
{
	t_list	*current;

	current = NULL;
	if (algo->instruction_count)
	{
		if (instruction == SA || instruction == SB)
			current = _skip(algo, SS);
		if (instruction == RA || instruction == RB)
			current = _skip(algo, RR);
		if (instruction == RRA || instruction == RRB)
			current = _skip(algo, RRR);
		if ((instruction == SA && *((t_uint *)current->data) == SB)
			|| (instruction == SB && *((t_uint *)current->data) == SA))
			return (current->data = instruction_tab + SS, EXIT_SUCCESS);
		if ((instruction == RA && *((t_uint *)current->data) == RB)
			|| (instruction == RB && *((t_uint *)current->data) == RA))
			return (current->data = instruction_tab + RR, EXIT_SUCCESS);
		if ((instruction == RRA && *((t_uint *)current->data) == RRB)
			|| (instruction == RRB && *((t_uint *)current->data) == RRA))
			return (current->data = instruction_tab + RRR, EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

void	add_instruction(t_push_swap *ps, t_uint instruction)
{
	t_list			*new;
	t_algo			*algo;
	static t_uint	instruction_tab[INSTRUCTION_COUNT]
		= {SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};

	algo = get_algo(ps);
	if (DEBUG || _remove_instruction(algo, instruction))
	{
		if (DEBUG || _fact_instruction(algo, instruction, instruction_tab))
		{
			new = ft_lstnew(instruction_tab + instruction);
			if (!new)
				push_swap_end(ps, ERRLOC, EXIT_FAILURE);
			ft_lstadd_front(&algo->instruction, new);
			algo->instruction_count++;
		}
	}
}
