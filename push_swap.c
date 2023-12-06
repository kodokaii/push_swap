/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:23:53 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/06 03:24:03 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_print_instruction(t_uint *instruction)
{
	static char	*instruction_str[INSTRUCTION_COUNT]
		= {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};

	ft_putendl_fd(instruction_str[*instruction], STDOUT_FILENO);
}

static void	_algo_init(t_push_swap *ps)
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

static void	_run_algo(t_push_swap *ps, void (*algo)(t_push_swap *))
{
	ps->algo_index++;
	_algo_init(ps);
	algo(ps);
}

void	push_swap_end(t_push_swap *ps, char *error_msg, int error)
{
	t_uint	algo_count;

	algo_count = ps->algo_index + 1;
	if (!error)
		ft_lstiter_inv(best_algo(ps->algo, algo_count)->instruction,
			_print_instruction);
	while (algo_count--)
	{
		ft_lstclear(&ps->algo[algo_count].pile[A].lst, NULL);
		ft_lstclear(&ps->algo[algo_count].pile[B].lst, NULL);
		ft_lstclear(&ps->algo[algo_count].instruction, NULL);
	}
	free(ps->tab);
	if (error_msg)
		ft_dprintf(STDOUT_FILENO, "%s\n", error_msg);
	if (error)
		exit(error);
}

void	push_swap(t_uint *tab, t_uint tab_size)
{
	t_push_swap	ps;

	ps.tab = tab;
	ps.tab_size = tab_size;
	ps.algo_index = -1;
//	_run_algo(&ps, radix_sort);
//	_run_algo(&ps, quick_sort);
	//_run_algo(&ps, merge_sort);
	_run_algo(&ps, high_sort);
	push_swap_end(&ps, NULL, EXIT_SUCCESS);
}
