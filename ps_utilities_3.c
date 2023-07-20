/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utilities_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:24:13 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/07/20 23:49:05 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_count_add(t_ps *tab, t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	tab->i = 0;
	while (temp != NULL)
	{
		tab->i++;
		temp = temp->next;
	}
	return (tab->i);
}

void	node_count(t_ps *tab, t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	(void)stack_b;
	tab->i = 0;
	temp = *stack_a;
	while (*stack_a != NULL)
	{
		tab->i++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = temp;
	if (tab->i <= 3)
		stack_of_3(stack_a, tab);
	else if (tab->i > 3 && tab->i <= 5)
		stack_of_5(stack_a, stack_b, tab);
	else
		stack_of_100(stack_a, stack_b, tab);
}

void	moves_2_add(t_list **stack_a, t_list **stack_b, t_ps *tab)
{
	if (tab->final_direction_a == tab->final_direction_b
		&& tab->final_direction_a == 0)
	{
		while (tab->operations_a != 0 && tab->operations_b != 0)
		{
			rr_shift_down(stack_a, stack_b);
			tab->operations_a--;
			tab->operations_b--;
		}
	}
	while (tab->final_direction_a == 0 && tab->operations_a != 0)
	{
		shift_down(stack_a, 'a');
		tab->operations_a--;
	}
	while (tab->final_direction_b == 0 && tab->operations_b != 0)
	{
		shift_down(stack_b, 'b');
		tab->operations_b--;
	}
}

void	moves_2(t_list **stack_a, t_list **stack_b, t_ps *tab)
{
	if (tab->final_direction_a == tab->final_direction_b
		&& tab->final_direction_a == 1)
	{
		while (tab->operations_a != 0 && tab->operations_b != 0)
		{
			rr_shift_up(stack_a, stack_b);
			tab->operations_a--;
			tab->operations_b--;
		}
	}
	while (tab->final_direction_a == 1 && tab->operations_a != 0)
	{
		shift_up(stack_a, 'a');
		tab->operations_a--;
	}
	while (tab->final_direction_b == 1 && tab->operations_b != 0)
	{
		shift_up(stack_b, 'b');
		tab->operations_b--;
	}
	moves_2_add(stack_a, stack_b, tab);
}

int	find_shortest_dist(t_list **stack, t_ps *tab, int element)
{
	int		distance_from_top;
	int		dist_from_bottom;
	t_list	*current;

	distance_from_top = 0;
	current = *stack;
	while (current != NULL)
	{
		if (current->index == element)
			break ;
		distance_from_top++;
		current = current->next;
	}
	dist_from_bottom = distance_from_bottom(stack, element);
	if (distance_from_top < dist_from_bottom)
	{
		tab->direction_a = 1;
		return (distance_from_top);
	}
	else
	{
		tab->direction_a = 0;
		return (dist_from_bottom);
	}
}
