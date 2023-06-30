/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:31:39 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/07/01 00:53:42 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int distance_from_top(t_list **stack) 
{
    int distance = 0;
    t_list *current = *stack;
    int biggest = find_biggest_number(stack)->index;  // Assuming this returns the biggest index

    while (current != NULL && current->index != biggest) {
        distance++;
        current = current->next;
    }

    return distance;
}

int distance_from_bottom(t_list **stack, int target_index) 
{
    int distance = 0;
    t_list *current = *stack;
    while (current != NULL && current->index != target_index)
        current = current->next;
    while (current != NULL) 
    {
        distance++;
        current = current->next;
    }
    
    return distance;
}

int distance_to_biggest(t_list **stack) {
    int biggest = find_biggest_number(stack)->index;
    int top_distance = distance_from_top(stack);
    int bottom_distance = distance_from_bottom(stack, biggest);
    
    if (top_distance < bottom_distance)
        return top_distance;
    else
        return bottom_distance;
}


int find_insert_position(t_list **stack, int element, t_ps *tab) 
{
    int     distance_from_top;
    t_list  *current;
    t_list  *copy;
    int     distance_from_bottom;
    int     closest_smaller;

    distance_from_top = 0;
    distance_from_bottom = 0;
    current = *stack;
    copy = current;
    closest_smaller = find_closest_smaller(&current, tab, element);
    if (current == NULL) 
        return distance_from_top;
    while (current != NULL && current->index != closest_smaller) 
    { 
        if(closest_smaller == INT_MIN)
            return (distance_to_biggest(stack));
        distance_from_top++;
        current = current->next;
    }
    if (distance_from_bottom == 0)
        distance_from_bottom = node_count_add(tab, stack) - distance_from_top;
    if (distance_from_top < distance_from_bottom)
    {
        tab->direction_b = 1;
		return (distance_from_top);
    }
	else
    {
        tab->direction_b = 0;
		return (distance_from_bottom);
        // remember to put what happens if they are equal;
    }
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
    {
        tab->direction_a = 1;
		return (distance_from_top);
    }
	else
    {
        tab->direction_a = 0;
		return (distance_from_bottom);
    }
}

void    moves_2(t_list **stack_a, t_list **stack_b, t_ps *tab)
{
        t_list *current_a;
        t_list *current_b;

        current_a = *stack_a;
        current_b = *stack_b;
        if (tab->direction_a == tab->direction_b && tab->direction_a == 1)
        {
            while (tab->operations_a != 0 && tab->operations_b != 0)
		    {
			    rr_shift_up(stack_a, stack_b);
                tab->operations_a--;
                tab->operations_b--;
		    }
        }
        while (tab->direction_a == 1 && tab->operations_a != 0)
        {
            shift_up(stack_a, 'a');
            tab->operations_a--;
        }
        while (tab->direction_b == 1 && tab->operations_b != 0)
        {
            shift_up(stack_b, 'b');
            tab->operations_b--;
        }
        if (tab->direction_a == tab->direction_b && tab->direction_a == 0)
        {
            while (tab->operations_a != 0 && tab->operations_b != 0)
		    {
			    rr_shift_down(stack_a, stack_b);
                tab->operations_a--;
                tab->operations_b--;
		    }
        }
        while (tab->direction_a == 0 && tab->operations_a != 0)
        {
            shift_down(stack_a, 'a');
            tab->operations_a--;
        }
        while (tab->direction_b == 0 && tab->operations_b != 0)
        {
            shift_down(stack_b, 'b');
            tab->operations_b--;
        } 
    printf("Printing after moves\n");
    printing(*stack_a, *stack_b);
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
    
    push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
    printing(*stack_a, *stack_b);
    current = *stack_a;
    operations_a = 0;
    operations_b = 0;
    total_operations = 0;
    double_operations = 0;

    while (node_count_add(tab, stack_a) > 0)
    {
        min_operations = INT_MAX;
        while(current) 
        {
            element = current->index;
            
            operations_a = ft_find_shortest_distance(stack_a, element, tab);
            operations_b = find_insert_position(stack_b, element, tab);
            printf("%d\n", element);
            printf("operations_a %d\n", operations_a);
            printf("direction_a %d\n", tab->direction_a);
            printf("operations_b %d\n", operations_b);
             printf("direction_b %d\n", tab->direction_b);
            printf("\n");
            if (tab->direction_a == tab->direction_b)
            {
                if (operations_a >= operations_b)
                    total_operations = operations_a;
                else 
                    total_operations = operations_b;
            }
            else
                total_operations = operations_a + operations_b;
            if(total_operations < min_operations) 
            {
                min_operations = total_operations;
                min_element = element;
                current->if_min_element = 1;
                tab->operations_a = operations_a;
                tab->operations_b = operations_b;
            }
            current = current->next;
        }
        printf("Minimal cost element: %d\n", min_element);
        printf("\n");
        moves_2(stack_a, stack_b, tab);
        push(stack_a, stack_b, 'b');
        printing(*stack_a, *stack_b);
        current = *stack_a;
    }
    //stack_of_3(stack_a);
    /*while (if_sorted(stack_b) == 1)
		shift_up(stack_b, 'b');*/
    //printf("Minimal cost element: %d\n", min_element);
    //to see what can be doe with moves function, why it doesn't work and also check if anything else has to be add to the struckt to reflect the direction of the further movements.
    printing(*stack_a, *stack_b);
}