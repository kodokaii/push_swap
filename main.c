/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:14:01 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/27 17:53:24 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_error(char **argv, int *tab)
{
	free(tab);
	ft_split_free(argv);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}

static int	_sort_tab(int *tab, int *tab_sort, int count)
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
	if (1 < before_count && _sort_tab(tab, tab_sort, before_count))
		return (EXIT_FAILURE);
	if (1 < after_count && _sort_tab(tab,
			tab_sort + before_count + 1, after_count))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	_normalize_tab(int *tab, int tab_size)
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
	if (_sort_tab(tab, tab_sort, tab_size))
	{
		free(tab_sort);
		return (EXIT_FAILURE);
	}
	i = 0;
	while (i < tab_size)
	{
		tab[tab_sort[i]] = i + 1;
		i++;
	}
	free(tab_sort);
	return (EXIT_SUCCESS);
}

static int	_argv_to_tab(int *tab, int argc, char **argv)
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

int	main(int argc, char *argv[])
{
	int		*tab;

	if (1 < argc)
	{
		argc--;
		argv++;
		tab = NULL;
		if (ft_split_argv(&argc, &argv))
			return (_error(argv, tab));
		tab = malloc(argc * sizeof(int));
		if (_argv_to_tab(tab, argc, argv))
			return (_error(argv, tab));
		if (_normalize_tab(tab, argc))
			return (_error(argv, tab));
		if (push_swap((t_uint *)tab, argc))
			return (_error(argv, tab));
		ft_split_free(argv);
		free(tab);
	}
	return (EXIT_SUCCESS);
}
