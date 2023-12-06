/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/06 21:12:28 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define INSTRUCTION_COUNT 11
# define PILE_COUNT 2
# define ALGO_COUNT 4

# define A 0
# define B 1

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
	t_uint	count;
	t_list	*lst;
}	t_pile;

typedef struct s_algo
{
	t_uint	all_count;
	t_pile	pile[PILE_COUNT];
	t_uint	instruction_count;
	t_list	*instruction;
}	t_algo;

typedef struct s_push_swap
{
	t_uint	*tab;
	t_uint	tab_size;	
	t_uint	algo_index;
	t_algo	algo[ALGO_COUNT];
}	t_push_swap;

int		sort_tab_index(int *tab, int *tab_sort, int count);
int		normalize_tab(int *tab, int tab_size);
int		argv_to_tab(int *tab, int argc, char **argv);

void	push_swap_end(t_push_swap *ps, char *error_msg, int error);
void	push_swap(t_uint *tab, t_uint tab_size);

void	radix_sort(t_push_swap *ps);
void	quick_sort(t_push_swap *ps);
void	merge_sort(t_push_swap *ps);
void	high_sort(t_push_swap *ps);

void	swap(t_push_swap *ps, t_uint pile_index);
void	push(t_push_swap *ps, t_uint pile_index);
void	rotate(t_push_swap *ps, t_uint pile_index);
void	reverse_rotate(t_push_swap *ps, t_uint pile_index);
void	action(t_push_swap *ps, t_uint instruction);

void	script(t_push_swap *ps, t_uint count, ...);
void	tiny_sort(t_push_swap *ps);
void	best_sort(t_push_swap *ps);

t_uint	*get_config(t_push_swap *ps, t_uint count, t_uint pile_index);
t_bool	is_same_config(t_uint *config1, t_uint *config2, t_uint count);

t_list	*skip_instruction(t_push_swap *ps, t_uint instruction);
t_list	**skip_instruction_a(t_push_swap *ps);
t_list	**skip_instruction_b(t_push_swap *ps);

t_bool	is_instruction(t_uint instruction, t_uint count, ...);
t_uint	inverse_instruction(t_uint instruction);
t_uint	count_instruction(t_push_swap *ps, t_uint instruction);
void	delete_next_instruction(t_push_swap *ps, t_list **instruction_lst);
void	delete_instruction(t_push_swap *ps);
void	add_instruction(t_push_swap *ps, t_uint instruction);
void	new_instruction(t_push_swap *ps, t_uint instruction);

t_algo	*get_algo(t_push_swap *ps);
t_pile	*get_pile(t_push_swap *ps, t_uint pile_index);
t_uint	get_top(t_push_swap *ps, t_uint pile_index);
t_uint	get_bot(t_push_swap *ps, t_uint pile_index);
t_uint	*get_instruction(t_uint instruction);

t_algo	*best_algo(t_algo *algo, t_uint algo_count);
t_uint	count_sort(t_push_swap *ps);
void	run_algo(t_push_swap *ps, void (*algo)(t_push_swap *));
void	algo_init(t_push_swap *ps);
void	print_instruction(t_uint *instruction);

#endif
