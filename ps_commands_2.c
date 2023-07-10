/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:40:29 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/07/10 22:49:12 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	shift_down(t_list **stack, char c)
{
	t_list	*temp;
	t_list	*last;

	temp = *stack;
	if (c != 'c' && c == 'a')
		write(1, "rra\n", 4);
	else if (c != 'c' && c == 'b')
		write(1, "rrb\n", 4);
	if (temp && temp->next)
	{
		while (temp->next != NULL)
		{
			last = temp;
			temp = temp->next;
		}
		temp->next = *stack;
		last->next = NULL;
		*stack = temp;
	}
	else
		return (1);
	return (0);
}

int	rr_shift_down(t_list **stack_a, t_list **stack_b)
{
	write(1, "rrr\n", 4);
	if (*stack_a && stack_b)
	{
		shift_down(stack_a, 'c');
		shift_down(stack_b, 'c');
	}
	else
		return (1);
	return (0);
}
