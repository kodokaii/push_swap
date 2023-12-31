/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/07 05:27:16 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	_exec_instruction(t_push_swap *ps, char *instruction)
{
	if (!ft_strcmp(instruction, "sa\n"))
		action(ps, SA);
	else if (!ft_strcmp(instruction, "sb\n"))
		action(ps, SB);
	else if (!ft_strcmp(instruction, "ss\n"))
		action(ps, SS);
	else if (!ft_strcmp(instruction, "pa\n"))
		action(ps, PA);
	else if (!ft_strcmp(instruction, "pb\n"))
		action(ps, PB);
	else if (!ft_strcmp(instruction, "ra\n"))
		action(ps, RA);
	else if (!ft_strcmp(instruction, "rb\n"))
		action(ps, RB);
	else if (!ft_strcmp(instruction, "rr\n"))
		action(ps, RR);
	else if (!ft_strcmp(instruction, "rra\n"))
		action(ps, RRA);
	else if (!ft_strcmp(instruction, "rrb\n"))
		action(ps, RRB);
	else if (!ft_strcmp(instruction, "rrr\n"))
		action(ps, RRR);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	_check_algo(t_push_swap *ps)
{
	char	*instruction;
	int		fd;

	fd = STDIN_FILENO;
	instruction = ft_gnl(STDIN_FILENO).buf;
	while (instruction)
	{
		if (_exec_instruction(ps, instruction))
		{
			free(instruction);
			ft_close(&fd);
			push_swap_end(ps, "Error", EXIT_FAILURE);
		}
		free(instruction);
		instruction = ft_gnl(STDIN_FILENO).buf;
	}
	ft_close(&fd);
	if (count_sort(ps) == get_algo(ps)->all_count)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
}

void	checker(t_uint *tab, t_uint tab_size)
{
	t_push_swap	ps;

	ps.tab = tab;
	ps.tab_size = tab_size;
	ps.algo_index = -1;
	run_algo(&ps, _check_algo);
	push_swap_end(&ps, NULL, EXIT_SUCCESS);
}
