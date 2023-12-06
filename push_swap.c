/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:23:53 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/06 21:34:59 by nlaerema         ###   ########.fr       */
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

void	push_swap_end(t_push_swap *ps, char *error_msg, int error)
{
	t_uint	algo_count;

	algo_count = ps->algo_index + 1;
	if (!error && algo_count)
		ft_lstiter_inv(best_algo(ps->algo, algo_count)->instruction,
			print_instruction);
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
	if (!_is_sort(tab, tab_size))
	{
		run_algo(&ps, radix_sort);
		run_algo(&ps, quick_sort);
		run_algo(&ps, merge_sort);
		run_algo(&ps, high_sort);
	}
	push_swap_end(&ps, NULL, EXIT_SUCCESS);
}
