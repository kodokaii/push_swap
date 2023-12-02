/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/02 01:57:29 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_useless_instruction(t_uint instruction, t_uint last_instruction)
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

t_list	*skip_instruction(t_pile *pile, t_uint instruction)
{
	t_list	*current;

	current = pile->instruction;
	while (current && *((t_uint *)current->data) == instruction)
		current = current->next;
	return (current);
}

void	print_instruction(t_uint *instruction)
{
	static char	*instruction_str[INSTRUCTION_COUNT]
		= {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};

	ft_putstr_fd(instruction_str[*instruction], STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
