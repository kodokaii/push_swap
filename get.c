/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/02 17:39:31 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_algo	*get_algo(t_push_swap *ps)
{
	return (ps->algo + ps->algo_index);
}

t_pile	*get_pile(t_push_swap *ps, t_uint pile_index)
{
	return (ps->algo[ps->algo_index].pile + pile_index);
}

t_uint	get_top(t_push_swap *ps, t_uint pile_index)
{
	return (*((t_uint *)ps->algo[ps->algo_index].pile[pile_index].lst->data));
}

t_uint	get_bot(t_push_swap *ps, t_uint pile_index)
{
	return (*((t_uint *)
			ft_lstlast(ps->algo[ps->algo_index].pile[pile_index].lst)->data));
}
