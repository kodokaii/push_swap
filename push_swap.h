/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/10 22:50:45 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_pile
{
	int		all_count;
	int		a_count;
	int		b_count;
	t_list	*a;
	t_list	*b;
}	t_pile;

int		push_swap(int *tab, int tab_size);

void	push_a(t_pile *pile);
void	push_b(t_pile *pile);
void	swap_a(t_pile *pile);
void	swap_b(t_pile *pile);
void	swap_swap(t_pile *pile);
void	rotate_a(t_pile *pile);
void	rotate_b(t_pile *pile);
void	rotate_rotate(t_pile *pile);
void	reverse_rotate_a(t_pile *pile);
void	reverse_rotate_b(t_pile *pile);
void	reverse_rotate_rotate(t_pile *pile);

#endif
