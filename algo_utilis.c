/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/05 23:32:59 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dup_algo(t_algo *algo_dst, t_algo *algo_src)
{
	if (ft_lstdup(algo_dst->pile[A].lst, algo_src->pile[A].lst))
		return (EXIT_FAILURE);
	if (ft_lstdup(algo_dst->pile[B].lst, algo_src->pile[B].lst))
	{
		ft_lstclear(&algo_dst->pile[A].lst, NULL);
		return (EXIT_FAILURE);
	}
	if (ft_lstdup(algo_dst->instruction, algo_src->instruction))
	{
		ft_lstclear(&algo_dst->pile[A].lst, NULL);
		ft_lstclear(&algo_dst->pile[B].lst, NULL);
		return (EXIT_FAILURE);
	}
	algo_dst->all_count = algo_src->all_count;
	algo_dst->pile[A].count = algo_src->pile[A].count;
	algo_dst->pile[B].count = algo_src->pile[B].count;
	algo_dst->instruction_count = algo_src->instruction_count;
	return (EXIT_SUCCESS);
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
