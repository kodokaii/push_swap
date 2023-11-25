/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/24 16:04:23 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_count(t_pile *pile)
{
	t_list	*current;
	int		res;
	int		i;

	i = 1;
	res = 0;
	current = pile->a;
	while (i <= pile->a_count)
	{
		if (i == *(int *)current->data)
			res++;
		current = current->next;
		i++;
	}
	return (res);
}
