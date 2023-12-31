/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:45:22 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/07/21 00:45:12 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_list **stack_a, int argc, t_ps *tab)
{
	t_list	*current;
	t_list	*min_node;
	int		min;

	current = *stack_a;
	changing_tabs(tab, &argc);
	while (tab->i <= argc - 1)
	{
		min = INT_MAX;
		while (current)
		{
			if (current->content < min && current->index == 0)
			{
				min = current->content;
				min_node = current;
			}
			current = current->next;
		}
		min_node->index = tab->i;
		tab->i++;
		current = *stack_a;
	}
}

void	stack_of_3(t_list **stack_a, t_ps *tab)
{
	if (if_sorted(stack_a) == 1)
	{
		if (*stack_a == find_biggest_number(stack_a, tab))
			shift_up(stack_a, 'a');
		else if ((*stack_a)->next == find_biggest_number(stack_a, tab))
			shift_down(stack_a, 'a');
		if (if_sorted(stack_a) == 1)
			swap(stack_a, 'a');
	}
}

void	moves(t_list **stack_a, t_ps *tab)
{
	if (tab->position > (node_count_add(tab, stack_a)) / 2)
	{
		while (tab->b < (node_count_add(tab, stack_a) - tab->position))
		{
			shift_down(stack_a, 'a');
			tab->b++;
		}
	}
	else
	{
		while (tab->b < tab->position)
		{
			shift_up(stack_a, 'a');
			tab->b++;
		}
	}
}

void	stack_of_5_add(t_list **stack_a, t_list **stack_b, t_ps *tab)
{
	if (if_sorted(stack_a) == 1)
	{
		if (node_count_add(tab, stack_a) == 4)
		{
			push(stack_a, stack_b, 'b');
			stack_of_3(stack_a, tab);
		}
		else 
		{
			push(stack_a, stack_b, 'b');
			push(stack_a, stack_b, 'b');
			stack_of_3(stack_a, tab);
		}
	}
}

void	stack_of_5(t_list **stack_a, t_list **stack_b, t_ps *tab)
{
	stack_of_5_add(stack_a, stack_b, tab);
	while (*stack_b)
	{
		tab->i = 0;
		tab->b = 0;
		tab->position = INT_MAX;
		tab->position = find_closest_bigger(stack_a, stack_b, tab);
		if (tab->position == INT_MAX)
		{
			while (if_sorted(stack_a) == 1)
				shift_up(stack_a, 'a');
			push(stack_b, stack_a, 'a');
			shift_up(stack_a, 'a');
		}
		else
		{
			moves(stack_a, tab);
			push(stack_b, stack_a, 'a');
		}
	}
	while (if_sorted(stack_a) == 1)
		shift_up(stack_a, 'a');
}
