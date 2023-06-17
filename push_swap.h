/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:13:40 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/06/08 20:06:04 by vkhrabro         ###   ########.fr       */
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
void	stack_of_3(t_list **stack_a);
void	indexing(t_list **stack, int argc, t_ps *tab);

#endif
