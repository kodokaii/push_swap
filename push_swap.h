/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/02 02:49:51 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define INSTRUCTION_COUNT 11
# define ALGO_COUNT 2

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

typedef struct s_pile
{
	t_uint	all_count;
	t_uint	a_count;
	t_uint	b_count;
	t_list	*a;
	t_list	*b;
	t_uint	instruction_count;
	t_list	*instruction;
}	t_pile;

int		push_swap(t_uint *tab, t_uint tab_size);

int		add_instruction(t_pile *pile, t_uint instruction);
t_bool	is_useless_instruction(t_uint instruction, t_uint last_instruction);
t_list	*skip_instruction(t_pile *pile, t_uint instruction);
void	print_instruction(t_uint *instruction);

int		radix_sort(t_pile *pile, t_uint *tab, t_uint tab_size);
int		quick_sort(t_pile *pile, t_uint *tab, t_uint tab_size);

int		pile_init(t_pile *pile, t_uint *tab, t_uint tab_size);
t_uint	sort_count(t_pile *pile);

int		push_a(t_pile *pile);
int		push_b(t_pile *pile);
int		swap_a(t_pile *pile);
int		swap_b(t_pile *pile);
int		swap_swap(t_pile *pile);
int		rotate_a(t_pile *pile);
int		rotate_b(t_pile *pile);
int		rotate_rotate(t_pile *pile);
int		reverse_rotate_a(t_pile *pile);
int		reverse_rotate_b(t_pile *pile);
int		reverse_rotate_rotate(t_pile *pile);

#endif
