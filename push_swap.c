/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/25 17:15:02 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_end(int error, t_pile *pile)
{
	ft_lstclear(&pile->a, NULL);
	ft_lstclear(&pile->b, NULL);
	return (error);
}

static int	_init(int *tab, int tab_size, t_pile *pile)
{
	t_list	*new;

	pile->all_count = tab_size;
	pile->a_count = tab_size;
	pile->b_count = 0;
	pile->a = NULL;
	pile->b = NULL;
	while (tab_size--)
	{
		new = ft_lstnew(tab + tab_size);
		if (!new)
			return (EXIT_FAILURE);
		ft_lstadd_front(&pile->a, new);
	}
	return (EXIT_SUCCESS);
}

void	nb_print(int *nb, int fd)
{
	ft_putint_fd(*nb, fd);
}

void	pile_print(t_pile *pile)
{
	ft_printf("A: ");
	ft_putlst_fd(pile->a, &nb_print, STDOUT_FILENO);
	ft_printf("\nB: ");
	ft_putlst_fd(pile->b, &nb_print, STDOUT_FILENO);
	ft_printf("\n\n");
}

int	push_swap(int *tab, int tab_size)
{
	t_pile	pile;

	if (_init(tab, tab_size, &pile))
		return (_end(EXIT_FAILURE, &pile));
	pile_print(&pile);
	push_b(&pile);
	pile_print(&pile);
	swap_b(&pile);
	pile_print(&pile);
	ft_printf("\nsort = %d\n", sort_count(&pile));
	return (_end(EXIT_SUCCESS, &pile));
}
