/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/06 20:31:38 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_init_bind(t_push_swap *ps, t_uint *bind)
{
	t_list	*current_a;
	t_list	*current_b;
	t_uint	b_index;
	t_uint	a_index;
	t_uint	nb_max;

	b_index = -1;
	current_b = get_pile(ps, B)->lst;
	while (++b_index < get_pile(ps, B)->count)
	{
		a_index = -1;
		nb_max = UINT_MAX;
		current_a = get_pile(ps, A)->lst;
		while (++a_index < get_pile(ps, A)->count)
		{
			if (*((t_uint *)current_b->data) < *((t_uint *)current_a->data)
				&& *((t_uint *)current_a->data) < nb_max)
			{
				nb_max = *((t_uint *)current_a->data);
				bind[b_index] = a_index;
			}
			current_a = current_a->next;
		}
		current_b = current_b->next;
	}
}

static t_uint	_get_score(t_push_swap *ps, t_uint *bind, t_uint i)
{
	t_uint	score;
	t_uint	a_count;
	t_uint	b_count;

	a_count = get_pile(ps, A)->count;
	b_count = get_pile(ps, B)->count;
	if (i * 2 < b_count)
	{
		if (bind[i] * 2 < a_count)
			score = ft_max_uint(i, bind[i]);
		else
			score = i + a_count - bind[i];
	}
	else
	{
		if (bind[i] * 2 < a_count)
			score = b_count - i + bind[i];
		else
			score = ft_max_uint(b_count - i, a_count - bind[i]);
	}
	return (score);
}

static void	_find_best_bind(t_push_swap	*ps, t_uint *bind, t_uint *best)
{
	t_list	*current_b;
	t_uint	best_score;
	t_uint	nb_max;
	t_uint	score;
	t_uint	i;

	i = 0;
	nb_max = 0;
	current_b = get_pile(ps, B)->lst;
	best_score = UINT_MAX;
	while (current_b)
	{
		score = _get_score(ps, bind, i);
		if (score < best_score
			|| (score == best_score && nb_max < *((t_uint *)current_b->data)))
		{
			nb_max = *((t_uint *)current_b->data);
			best_score = score;
			*best = i;
		}
		current_b = current_b->next;
		i++;
	}
}

static void	_exec_bind(t_push_swap *ps, t_uint *bind)
{
	t_uint	from_index;
	t_uint	to_index;

	_find_best_bind(ps, bind, &from_index);
	to_index = bind[from_index];
	while (to_index--)
		action(ps, RA);
	while (from_index--)
		action(ps, RB);
	action(ps, PA);
}

void	best_sort(t_push_swap *ps)
{
	t_uint	*bind;
	t_pile	*pile_b;

	pile_b = get_pile(ps, B);
	if (pile_b->count)
	{
		bind = malloc(pile_b->count * sizeof(t_uint));
		if (!bind)
		{
			free(bind);
			push_swap_end(ps, ERRLOC, EXIT_FAILURE);
		}
		while (pile_b->count)
		{
			_init_bind(ps, bind);
			_exec_bind(ps, bind);
		}
		free(bind);
	}
	while (get_top(ps, A))
		action(ps, RA);
}
