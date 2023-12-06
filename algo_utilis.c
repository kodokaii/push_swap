/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/06 21:13:32 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_instruction(t_uint *instruction)
{
	static char	*instruction_str[INSTRUCTION_COUNT]
		= {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};

	ft_putendl_fd(instruction_str[*instruction], STDOUT_FILENO);
}

void	algo_init(t_push_swap *ps)
{
	t_list	*new;
	t_uint	tab_index;
	t_algo	*algo;

	algo = get_algo(ps);
	algo->all_count = ps->tab_size;
	algo->pile[A].count = ps->tab_size;
	algo->pile[A].lst = NULL;
	algo->pile[B].count = 0;
	algo->pile[B].lst = NULL;
	algo->instruction_count = 0;
	algo->instruction = NULL;
	tab_index = ps->tab_size;
	while (tab_index--)
	{
		new = ft_lstnew(ps->tab + tab_index);
		if (!new)
			push_swap_end(ps, ERRLOC, EXIT_FAILURE);
		ft_lstadd_front(&algo->pile[A].lst, new);
	}
}

void	run_algo(t_push_swap *ps, void (*algo)(t_push_swap *))
{
	ps->algo_index++;
	algo_init(ps);
	algo(ps);
}

t_algo	*best_algo(t_algo *algo, t_uint algo_count)
{
	t_uint	min_index;
	t_uint	min;
	t_uint	i;

	i = 0;
	min = UINT_MAX;
	min_index = UINT_MAX;
	while (i < algo_count)
	{
		if (algo[i].instruction_count < min)
		{
			min_index = i;
			min = algo[i].instruction_count;
		}
		i++;
	}
	return (algo + min_index);
}

t_uint	count_sort(t_push_swap *ps)
{
	t_pile	*pile;
	t_list	*current;
	t_uint	res;
	t_uint	i;

	i = 0;
	res = 0;
	pile = get_pile(ps, A);
	current = pile->lst;
	while (i < pile->count)
	{
		if (i == *(t_uint *)current->data)
			res++;
		current = current->next;
		i++;
	}
	return (res);
}
