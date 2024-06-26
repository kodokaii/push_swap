/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:23:53 by nlaerema          #+#    #+#             */
/*   Updated: 2024/04/14 20:37:28 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	_is_sort(t_uint *tab, t_uint tab_size)
{
	t_uint	i;

	i = 0;
	while (i + 1 < tab_size)
	{
		if (tab[i + 1] < tab[i])
			return (FT_FALSE);
		i++;
	}
	return (FT_TRUE);
}

static void	exec_best_algo(t_push_swap *ps)
{
	t_uint	algo_count;
	t_algo	*algo;

	algo_count = ps->algo_index + 1;
	algo = best_algo(ps->algo, algo_count);
	ft_lstiter_inv(algo->instruction, print_instruction);
}

void	push_swap_end(t_push_swap *ps, char *error_msg, int error)
{
	t_uint	algo_count;

	algo_count = ps->algo_index + 1;
	while (algo_count--)
	{
		ft_lstclear(&ps->algo[algo_count].pile[A].lst, NULL);
		ft_lstclear(&ps->algo[algo_count].pile[B].lst, NULL);
		ft_lstclear(&ps->algo[algo_count].instruction, NULL);
	}
	free(ps->tab);
	if (error_msg)
		ft_dprintf(STDERR_FILENO, "%s\n", error_msg);
	if (error)
		exit(error);
}

void	push_swap(t_uint *tab, t_uint tab_size)
{
	t_push_swap	ps;

	ps.tab = tab;
	ps.tab_size = tab_size;
	ps.algo_index = -1;
	if (!_is_sort(tab, tab_size))
	{
		run_algo(&ps, radix_ternary_sort);
		run_algo(&ps, radix_sort);
		run_algo(&ps, quick_sort);
		run_algo(&ps, merge_sort);
		run_algo(&ps, high_sort);
		exec_best_algo(&ps);
	}
	push_swap_end(&ps, NULL, EXIT_SUCCESS);
}
