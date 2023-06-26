/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:31:39 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/06/25 23:11:55 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_insert_position(t_list **stack, int element, t_ps *tab) 
{
    int     distance_from_top;
    t_list  *current;
    int     distance_from_bottom;
    int     closest_smaller;

    distance_from_top = 0;
    current = *stack;
    closest_smaller = find_closest_smaller(stack, tab, element);
    if (current == NULL) 
        return distance_from_top;
    while (current != NULL) 
    {
        if (current->index == closest_smaller)
            break;
        distance_from_top++;
        current = current->next;
    }
    distance_from_bottom = node_count_add(tab, stack) - distance_from_top;
    if (distance_from_top < distance_from_bottom)
		return (distance_from_top);
	else
		return (distance_from_bottom);
}


int	ft_find_shortest_distance(t_list **stack, int element, t_ps *tab)
{
	int distance_from_top;
	int distance_from_bottom;
	t_list *current;

	distance_from_top = 0;
	current = *stack;
    
	while (current != NULL)
	{
		if (current->index == element)
			break ;
		distance_from_top++;
		current = current->next;
	}
	distance_from_bottom = node_count_add(tab, stack) - distance_from_top;
	if (distance_from_top < distance_from_bottom)
		return (distance_from_top);
	else
		return (distance_from_bottom);
}

void	stack_of_100(t_list **stack_a, t_list **stack_b, t_ps *tab)
{
    t_list *current;
    int min_operations;
    int min_element;
    int element;
    int operations_a;
    int operations_b;
    int total_operations;
    int double_operations;
    
    min_operations = INT_MAX;
    
    push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
    current = *stack_a;
    operations_a = 0;
    operations_b = 0;
    total_operations = 0;
    double_operations = 0;

    while(current) 
    {
        element = current->index;
        operations_a = ft_find_shortest_distance(stack_a, element, tab);
        operations_b = find_insert_position(stack_b, element, tab);
        if ((operations_a > (node_count_add(tab, stack_a)) / 2) && (operations_b > (node_count_add(tab, stack_b)) / 2))
                double_operations = operations_a - operations_b;
        total_operations = operations_a + operations_b - double_operations;
        if(total_operations < min_operations) 
        {
            min_operations = total_operations;
            min_element = element;
            current->if_min_element = 1;
            current->operations_a = operations_a;
            current->operations_b = operations_b;
        }
        current = current->next;
    }
    printf("Minimal cost element: %d\n", min_element);
    //while loop which will look for the position of the min_element in stack a;
    //after = moving the min_element to the top + moving the closest_smaller in stack b to the top;
    //push from a to b;
    //repeat until only 3 numbers in stack_a are left;

    printing(*stack_a, *stack_b);
}