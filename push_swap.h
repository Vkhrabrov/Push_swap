/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vadimhrabrov <vadimhrabrov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:13:40 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/07/05 23:05:26 by vadimhrabro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/* malloc, free, exit */
# include <stdlib.h>

/* to write, read */
# include <unistd.h>

/* MAX_INT, MIN_INT */
# include <limits.h>

/* printf */
# include <stdio.h>

typedef struct s_ps
{
	int		i;
	long	b;
	int		k;
	int		position;
	int		direction_a;
	int		direction_b;
	int		final_direction_a;
	int		final_direction_b;
	int		operations_a;
	int		operations_b;
}	t_ps;

int		error_msg(char *first, int ret);
int		input_check(t_ps *tab, int argc, char **argv);
void	initialize_list(t_list **stack);
void	filling_stack_a(t_ps *tab, t_list **stack_a, int argc, char **argv);
int		swap(t_list **stack, char c);
int		s_swap(t_list **stack_a, t_list **stack_b);
int		push(t_list **src, t_list **dest, char c);
void	testing_grounds(t_ps *tab, t_list *stack_a, t_list *stack_b);
int		shift_up(t_list **stack, char c);
int		shift_down(t_list **stack, char c);
int		rr_shift_up(t_list **stack_a, t_list **stack_b);
void	printing(t_list *stack_a, t_list *stack_b);
int		rr_shift_down(t_list **stack_a, t_list **stack_b);
void	node_count(t_ps *tab, t_list **stack_a, t_list **stack_b);
void	stack_of_3(t_list **stack_a, t_ps *tab);
void	indexing(t_list **stack, int argc, t_ps *tab);
int		find_closest_bigger(t_list **stack_a, t_list **stack_b, t_ps *tab);
int		if_sorted(t_list **stack_a);
t_list	*find_biggest_number(t_list **stack_a, t_ps *tab);
void	stack_of_100(t_list **stack_a, t_list **stack_b, t_ps *tab);
int		node_count_add(t_ps *tab, t_list **stack);
int		find_closest_smaller(t_list **stack_b, t_ps *tab, int element);
int		if_sorted_from_biggest_to_smallest(t_list **stack);
#endif
