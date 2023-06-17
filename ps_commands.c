/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:14:36 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/06/02 21:21:48 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int swap(t_list **stack, char c)
{
    t_list *first;
    t_list *second;

    if (c == 'a')
        write(1, "sa\n", 3);
    else if (c == 'b')
        write(1, "sb\n", 3);
    if (*stack && (*stack)->next)
    {
        first = *stack;
        second = first->next;
        first->next = second->next;
        second->next = first;
        *stack = second;
    }
    else
        return (1);
    return (0);
}

int	s_swap(t_list **stack_a, t_list **stack_b)
{
	write(1, "ss\n", 4);
	if (*stack_a && *stack_b)
	{
		swap(stack_a, 'c');
		swap(stack_b, 'c');
	}
	else
		return (1);
	return (0);
}

int	push(t_list **src, t_list **dest, char c)
{
	t_list	*temp;

	if (c != 'c' && c == 'a')
		write(1, "pa\n", 3);
	else if (c != 'c' && c == 'b')
		write(1, "pb\n", 3);
	temp = *src;
	if (temp)
	{
		*src = (*src)->next;
		ft_lstadd_front(dest, temp);
	}
	else
		return (1);
	return (0);
}

int	shift_up(t_list **stack, char c)
{
	t_list	*temp;
	t_list	*last;

	if (c != 'c' && c == 'a')
		write(1, "ra\n", 3);
	else if (c != 'c' && c == 'b')
		write(1, "rb\n", 3);
	temp = *stack;
	if (temp)
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		last->next = temp;
		*stack = temp->next;
		temp->next = NULL;
	}
	else
		return (1);
	return (0);
}

int	rr_shift_up(t_list **stack_a, t_list **stack_b)
{
	write(1, "rr\n", 4);
	if (*stack_a && *stack_b)
	{
		shift_up(stack_a, 'c');
		shift_up(stack_b, 'c');
	}
	else
		return (1);
	return (0);
}
