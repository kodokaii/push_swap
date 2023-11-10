/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:14:01 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/10 21:52:14 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_tab(int *tab, int *tab_sort, int count)
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
	if (1 < before_count && sort_tab(tab, tab_sort, before_count))
		return (EXIT_FAILURE);
	if (1 < after_count && sort_tab(tab,
			tab_sort + before_count + 1, after_count))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	normalize_tab(int *tab, int tab_size)
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
	if (sort_tab(tab, tab_sort, tab_size))
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

static int	get_tab(int **tab, int argc, char **argv)
{
	int		i;
	char	*end;

	i = 0;
	tab = malloc(argc * sizeof(int));
	if (!tab)
		return (EXIT_FAILURE);
	while (i < argc)
	{
		(*tab)[i] = ft_strtoi(argv[i], &end);
		if (*end)
			return (EXIT_FAILURE);
		i++;
	}
	return (normalize_tab(*tab, argc));
}

int	main(int argc, char *argv[])
{
	int	*tab;

	if (0 < argc)
	{
		if (get_tab(&tab, --argc, ++argv))
		{
			free(tab);
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		if (push_swap(tab, argc))
		{
			free(tab);
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		free(tab);
	}
	return (EXIT_SUCCESS);
}
