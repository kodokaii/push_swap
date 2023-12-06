/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/06 01:06:45 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_tab_index(int *tab, int *tab_sort, int count)
{
	int	after_count;
	int	before_count;

	after_count = 0;
	before_count = 0;
	while (before_count + 1 + after_count < count)
	{
		if (tab[tab_sort[before_count + 1]] < tab[tab_sort[0]])
			before_count++;
		else if (tab[tab_sort[0]] < tab[tab_sort[before_count + 1]])
		{
			ft_swap_int(tab_sort + before_count + 1,
				tab_sort + count - after_count - 1);
			after_count++;
		}
		else
			return (EXIT_FAILURE);
	}
	ft_swap_int(tab_sort, tab_sort + before_count);
	if (1 < before_count && sort_tab_index(tab, tab_sort, before_count))
		return (EXIT_FAILURE);
	if (1 < after_count && sort_tab_index(tab,
			tab_sort + before_count + 1, after_count))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	normalize_tab(int *tab, int tab_size)
{
	int	*tab_sort;
	int	i;

	tab_sort = malloc(tab_size * sizeof(int));
	if (!tab_sort)
		return (EXIT_FAILURE);
	i = 0;
	while (i < tab_size)
	{
		tab_sort[i] = i;
		i++;
	}
	if (sort_tab_index(tab, tab_sort, tab_size))
	{
		free(tab_sort);
		return (EXIT_FAILURE);
	}
	i = 0;
	while (i < tab_size)
	{
		tab[tab_sort[i]] = i;
		i++;
	}
	free(tab_sort);
	return (EXIT_SUCCESS);
}

int	argv_to_tab(int *tab, int argc, char **argv)
{
	int		i;
	char	*end;

	i = 0;
	while (i < argc)
	{
		tab[i] = ft_strtoi(argv[i], &end);
		if (*end != '\0' || errno == ERANGE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
