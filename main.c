/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:14:01 by nlaerema          #+#    #+#             */
/*   Updated: 2024/02/16 18:51:39 by nlaerema         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	int		*tab;

	if (1 < argc)
	{
		argc--;
		argv++;
		tab = NULL;
		if (ft_split_argv(&argc, &argv))
			return (ft_errloc());
		tab = malloc(argc * sizeof(int));
		if (!tab)
		{
			ft_split_free(argv);
			return (ft_errloc());
		}
		if (argv_to_tab(tab, argc, argv))
			return (_error(argv, tab));
		if (normalize_tab(tab, argc))
			return (_error(argv, tab));
		ft_split_free(argv);
		push_swap((t_uint *)tab, argc);
	}
	return (EXIT_SUCCESS);
}
