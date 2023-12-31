/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:13:40 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/07/21 00:48:42 by vkhrabro         ###   ########.fr       */
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
	int		t;
	int		position;
	int		direction_a;
	int		direction_b;
	int		final_direction_a;
	int		final_direction_b;
	int		operations_a;
	int		operations_b;
	int		operations_a_add;
	int		operations_b_add;
	int		min_operations;
	int		total_operations;
	int		biggest;
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
int		sorted_from_biggest_to_smallest(t_list **stack);
void	stack_of_5(t_list **stack_a, t_list **stack_b, t_ps *tab);
int		distance_from_top(t_list **stack, t_ps *tab);
int		distance_from_bottom(t_list **stack, int element);
int		distance_to_biggest(t_list **stack, t_ps *tab);
int		if_sorted_from_biggest_to_smallest(t_list **stack);
void	moves_2(t_list **stack_a, t_list **stack_b, t_ps *tab);
int		find_shortest_dist(t_list **stack, t_ps *tab, int element);
void	free_list(t_list *head);
void	free_array(char **array, t_ps *tab);
void	safe_exit(t_ps *tab);
void	process_input(t_ps *tab, int *argc, char ***argv, char **argv_add);
void	check_input(t_ps *tab, int argc, char **argv, int i);
void	changing_tabs(t_ps *tab, int *argc);

#endif
