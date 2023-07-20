/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:31:39 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/07/12 20:35:29 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_inser_pos_add(int distance_from_top, int dist_from_bottom, t_ps *tab)
{
	if (distance_from_top < dist_from_bottom)
	{
		tab->direction_b = 1;
		return (distance_from_top);
	}
	else
	{
		tab->direction_b = 0;
		return (dist_from_bottom);
	}
}

int	find_insert_position(t_list **stack, t_ps *tab, int element)
{
	int		distance_from_top;
	int		dist_from_bottom;
	int		closest_smaller;
	t_list	*current;

	distance_from_top = 0;
	dist_from_bottom = 0;
	current = *stack;
	closest_smaller = find_closest_smaller(&current, tab, element);
	if (current == NULL)
		return (distance_from_top);
	while (current != NULL && current->index != closest_smaller)
	{
		if (closest_smaller == INT_MIN)
			return (distance_to_biggest(stack, tab));
		distance_from_top++;
		current = current->next;
	}
	if (dist_from_bottom == 0)
		dist_from_bottom = node_count_add(tab, stack) - distance_from_top;
	return (find_inser_pos_add (distance_from_top, dist_from_bottom, tab));
}

void	minimal_element_calculations(t_ps *tab)
{
	if (tab->direction_a == tab->direction_b)
	{
		if (tab->operations_a_add >= tab->operations_b_add)
			tab->total_operations = tab->operations_a_add;
		else
			tab->total_operations = tab->operations_b_add;
	}
	else
		tab->total_operations = tab->operations_a_add + tab->operations_b_add;
	if (tab->total_operations < tab->min_operations)
	{
		tab->min_operations = tab->total_operations;
		tab->operations_a = tab->operations_a_add;
		tab->operations_b = tab->operations_b_add;
		tab->final_direction_a = tab->direction_a;
		tab->final_direction_b = tab->direction_b;
	}
}

void	end_of_function_100(t_list **stack_a, t_list **stack_b, t_ps *tab)
{
	find_biggest_number(stack_b, tab);
	while (if_sorted_from_biggest_to_smallest(stack_b) == 1)
	{
		if (tab->position < node_count_add(tab, stack_b) / 2)
			shift_up(stack_b, 'b');
		else
			shift_down(stack_b, 'b');
	}
	while (*stack_b != NULL)
		push(stack_b, stack_a, 'a');
}

void	stack_of_100(t_list **stack_a, t_list **stack_b, t_ps *tab)
{
	int		element;
	t_list	*current;

	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	current = *stack_a;
	element = 0;
	while (node_count_add(tab, stack_a) > 0)
	{
		tab->min_operations = INT_MAX;
		while (current)
		{
			element = current->index;
			tab->operations_a_add = find_shortest_dist(stack_a, tab, element);
			tab->operations_b_add = find_insert_position(stack_b, tab, element);
			minimal_element_calculations(tab);
			current = current->next;
		}
		moves_2(stack_a, stack_b, tab);
		push(stack_a, stack_b, 'b');
		current = *stack_a;
	}
	end_of_function_100(stack_a, stack_b, tab);
}
