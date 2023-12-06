/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/06 01:53:32 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_uint	*get_config(t_push_swap *ps, t_uint count, t_uint pile_index)
{
	t_uint	*config;
	t_pile	*pile;
	t_list	*current;
	t_uint	i;

	pile = get_pile(ps, pile_index);
	if (pile->count < count)
		return (NULL);
	config = malloc(count * sizeof(t_uint));
	if (!config)
		return (NULL);
	i = 0;
	current = pile->lst;
	while (i < count)
	{
		config[i] = *((t_uint *)current->data);
		current = current->next;
		i++;
	}
	if (normalize_tab((int *)config, count))
	{
		free(config);
		return (NULL);
	}
	return (config);
}

t_bool	is_same_config(t_uint *config1, t_uint *config2, t_uint count)
{
	t_uint	i;

	i = 0;
	while (i < count && config1[i] == config2[i])
		i++;
	return (i == count);
}
