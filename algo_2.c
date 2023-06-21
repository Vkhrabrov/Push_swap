/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:31:39 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/06/21 21:59:12 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_insert_position(t_list *stack, int element) 
{
    int     distance_from_top;
    t_list  *current;
    int     distance_from_bottom;

    distance_from_top = 0;
    current = *stack;
    
    if (current == NULL) 
        return distance_from_top;
    while (current != NULL) 
    {
        if (current->index < element)
            break;
        distance_from_top++;
        current = current->next;
    }
    distance_from_bottom = size - distance_from_top;
    if (distance_from_top < distance_from_bottom)
		return (distance_from_top);
	else
		return (distance_from_bottom);
}


int	ft_find_shortest_distance(t_list *stack, int element)
{
	int size;
	int distance_from_top;
	int distance_from_bottom;
	t_list *current;

	size = ft_stack_size(stack);
	distance_from_top = 0;
	current = stack;
	while (current != NULL)
	{
		if (current->index == element)
			break ;
		distance_from_top++;
		current = current->next;
	}
	distance_from_bottom = size - distance_from_top;
	if (distance_from_top < distance_from_bottom)
		return (distance_from_top);
	else
		return (distance_from_bottom);
}

void	stack_of_100(t_list **stack_a, t_list **stack_b, t_ps *tab)
{
    t_list *current = *stack_a;
    int min_operations = INT_MAX;
    int min_element;
    int element;
    int operations_a;
    int operations_b;
    int total_operations;
    
    current = *stack_a;
    min_operation = INT_MAX;
    operation_a = 1;
    
    push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');

    while(current) 
    {
        element = current->index;
        operations_a += find_distance_from_top(*stack_a, element);
        operations_b = find_insert_position(*stack_b, element);
        total_operations = operations_a + operations_b;
        if(total_operations < min_operations) 
        {
            min_operations = total_operations;
            min_element = element;
        }
        current = current->next;
    }
    //while loop which will look for the position of the min_element in stack a;
    //after = moving the min_element to the top + moving the closest_smaller in stack b to the top;
    //push from a to b;
    //repeat until only 3 numbers in stack_a are left;

    printing(*stack_a, *stack_b);
}