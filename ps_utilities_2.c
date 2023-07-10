/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utilities_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:28:25 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/07/10 22:58:19 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_biggest_number(t_list **stack_a, t_ps *tab)
{
	t_list	*storage;
	t_list	*biggest_number;
	int		current_position;

	current_position = 0;
	storage = *stack_a;
	biggest_number = *stack_a;
	while (storage && storage->next)
	{
		current_position++;
		if ((biggest_number->index < storage->next->index))
		{
			biggest_number = storage->next;
			tab->position = current_position;
		}
		storage = storage->next;
	}
	return (biggest_number);
}

int	distance_from_top(t_list **stack, t_ps *tab)
{
	int		distance;
	int		biggest;
	t_list	*current;

	distance = 0;
	current = *stack;
	biggest = find_biggest_number(stack, tab)->index;
	while (current != NULL && current->index != biggest)
	{
		distance++;
		current = current->next;
	}
	return (distance);
}

int	distance_from_bottom(t_list **stack, int element)
{
	int		distance;
	t_list	*current;

	distance = 0;
	current = *stack;
	while (current != NULL && current->index != element)
		current = current->next;
	while (current != NULL)
	{
		distance++;
		current = current->next;
	}
	return (distance);
}

int	distance_to_biggest(t_list **stack, t_ps *tab)
{
	int	biggest;
	int	top_distance;
	int	bottom_distance;

	biggest = find_biggest_number(stack, tab)->index;
	top_distance = distance_from_top(stack, tab);
	bottom_distance = distance_from_bottom(stack, biggest);
	if (top_distance < bottom_distance)
	{
		tab->direction_b = 1;
		return (top_distance);
	}
	else
	{
		tab->direction_b = 0;
		return (bottom_distance);
	}
}
