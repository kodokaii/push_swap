/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/06 02:15:35 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	script(t_push_swap *ps, t_uint count, ...)
{
	va_list	arg;

	va_start(arg, count);
	while (count--)
		action(ps, va_arg(arg, t_uint));
	va_end(arg);
}

void	tiny_sort(t_push_swap *ps)
{
	t_uint	*config;	
	t_pile	*pile;

	pile = get_pile(ps, A);
	if (pile->count == 3)
	{
		config = get_config(ps, 3, A);
		if (!config)
			push_swap_end(ps, ERRLOC, EXIT_FAILURE);
		if (is_same_config(config, (t_uint [3]){0, 2, 1}, 3))
			script(ps, 2, RRA, SA);
		if (is_same_config(config, (t_uint [3]){1, 0, 2}, 3))
			action(ps, SA);
		if (is_same_config(config, (t_uint [3]){1, 2, 0}, 3))
			action(ps, RRA);
		if (is_same_config(config, (t_uint [3]){2, 0, 1}, 3))
			action(ps, RA);
		if (is_same_config(config, (t_uint [3]){2, 1, 0}, 3))
			script(ps, 2, SA, RRA);
		free(config);
	}
}
