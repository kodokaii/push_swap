/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/02 03:08:58 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_end(int error, t_pile *pile)
{
	t_uint	min_index;
	t_uint	min;
	t_uint	i;

	i = 0;
	min_index = 0;
	min = UINT_MAX;
	while (i < ALGO_COUNT)
	{
		if (pile[i].instruction_count < min)
		{
			min_index = i;
			min = pile[i].instruction_count;
		}
		i++;
	}
	ft_lstclear(&pile[min_index].instruction, print_instruction);
	while (i--)
	{
		ft_lstclear(&pile[i].a, NULL);
		ft_lstclear(&pile[i].b, NULL);
		ft_lstclear(&pile[i].instruction, NULL);
	}
	return (error);
}

static t_bool	_remove_instruction(t_pile *pile, t_uint instruction)
{
	t_list	*tmp;

	if (pile->instruction_count)
	{
		if (is_useless_instruction(instruction,
				*((t_uint *)pile->instruction->data)))
		{
			tmp = pile->instruction->next;
			free(pile->instruction);
			pile->instruction = tmp;
			pile->instruction_count--;
			return (FT_TRUE);
		}
	}
	return (FT_FALSE);
}

static t_bool	_fact_instruction(t_pile *pile,
		t_uint instruction, t_uint *instruction_tab)
{
	t_list	*current;

	current = NULL;
	if (pile->instruction_count)
	{
		if (instruction == SA || instruction == SB)
			current = skip_instruction(pile, SS);
		if (instruction == RA || instruction == RB)
			current = skip_instruction(pile, RR);
		if (instruction == RRA || instruction == RRB)
			current = skip_instruction(pile, RRR);
		if ((instruction == SA && *((t_uint *)current->data) == SB)
			|| (instruction == SB && *((t_uint *)current->data) == SA))
			return (current->data = instruction_tab + SS, FT_TRUE);
		if ((instruction == RA && *((t_uint *)current->data) == RB)
			|| (instruction == RB && *((t_uint *)current->data) == RA))
			return (current->data = instruction_tab + RR, FT_TRUE);
		if ((instruction == RRA && *((t_uint *)current->data) == RRB)
			|| (instruction == RRB && *((t_uint *)current->data) == RRA))
			return (current->data = instruction_tab + RRR, FT_TRUE);
	}
	return (FT_FALSE);
}

int	add_instruction(t_pile *pile, t_uint instruction)
{
	t_list			*new;
	static t_uint	instruction_tab[INSTRUCTION_COUNT]
		= {SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};

	if (_remove_instruction(pile, instruction))
		return (EXIT_SUCCESS);
	if (_fact_instruction(pile, instruction, instruction_tab))
		return (EXIT_SUCCESS);
	new = ft_lstnew(instruction_tab + instruction);
	if (!new)
		return (EXIT_FAILURE);
	ft_lstadd_front(&pile->instruction, new);
	pile->instruction_count++;
	return (EXIT_SUCCESS);
}

int	push_swap(t_uint *tab, t_uint tab_size)
{
	t_pile	pile[ALGO_COUNT];

	radix_sort(pile, tab, tab_size);
	quick_sort(pile + 1, tab, tab_size);
	return (_end(EXIT_SUCCESS, pile));
}
