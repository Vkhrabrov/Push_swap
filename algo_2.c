/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vadimhrabrov <vadimhrabrov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:31:39 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/07/05 23:28:51 by vadimhrabro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int distance_from_top(t_list **stack, t_ps *tab) 
{
    int distance = 0;
    t_list *current = *stack;
    int biggest = find_biggest_number(stack, tab)->index;  // Assuming this returns the biggest index

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

int distance_to_biggest(t_list **stack, t_ps *tab) {
    int biggest = find_biggest_number(stack, tab)->index;
    //printf("biggest: %d\n", biggest);
    int top_distance = distance_from_top(stack, tab);
    //printf("top_distance: %d\n", top_distance);
    int bottom_distance = distance_from_bottom(stack, biggest);
    //printf("bottom_distance: %d\n", bottom_distance);
    if (top_distance < bottom_distance)
    {
        //printf("I was here (top distance sent)\n");
        tab->direction_b = 1;
        return top_distance;
    }
    else
    {
        //printf("I was here (bottom distance sent)\n");
        tab->direction_b = 0;
        return bottom_distance;
    }
}


int find_insert_position(t_list **stack, int element, t_ps *tab) 
{
    int     distance_from_top;
    t_list  *current;
    int     dist_from_bottom;
    int     closest_smaller;

    distance_from_top = 0;
    dist_from_bottom = 0;
    current = *stack;
    closest_smaller = find_closest_smaller(&current, tab, element);
    //printf("closest_smaller: %d\n", closest_smaller);
    if (current == NULL) 
        return distance_from_top;
    while (current != NULL && current->index != closest_smaller) 
    { 
        if(closest_smaller == INT_MIN)
            return (distance_to_biggest(stack, tab));
        distance_from_top++;
        current = current->next;
    }
    //printf("distance_from_top: %d\n", distance_from_top);
    if (dist_from_bottom == 0)
        dist_from_bottom = node_count_add(tab, stack) - distance_from_top;
    //printf("dist_from_bottom: %d\n", dist_from_bottom);
    if (distance_from_top < dist_from_bottom)
    {
        tab->direction_b = 1;
		return (distance_from_top);
    }
	else
    {
        tab->direction_b = 0;
		return (dist_from_bottom);
        // remember to put what happens if they are equal;
    }
}


int	ft_find_shortest_distance(t_list **stack, int element, t_ps *tab)
{
	int distance_from_top;
	int dist_from_bottom;
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

void    moves_2(t_list **stack_a, t_list **stack_b, t_ps *tab)
{
        /*t_list *current_a;
        t_list *current_b;

        current_a = *stack_a;
        current_b = *stack_b; */
        if (tab->final_direction_a == tab->final_direction_b && tab->final_direction_a == 1)
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
        if (tab->final_direction_a == tab->final_direction_b && tab->final_direction_a == 0)
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
    //printf("Printing after moves\n");
    //printing(*stack_a, *stack_b);
}

void	stack_of_100(t_list **stack_a, t_list **stack_b, t_ps *tab)
{
    t_list *current;
    int min_operations;
    //int min_element;
    int element;
    int operations_a;
    int operations_b;
    int total_operations;
    
    push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
    //printing(*stack_a, *stack_b);
    current = *stack_a;
    operations_a = 0;
    operations_b = 0;
    total_operations = 0;

    while (node_count_add(tab, stack_a) > 0)
    {
        min_operations = INT_MAX;
        while(current) 
        {
            element = current->index;
            
            operations_a = ft_find_shortest_distance(stack_a, element, tab);
            operations_b = find_insert_position(stack_b, element, tab);
            //printf("%d\n", element);
            //printf("operations_a %d\n", operations_a);
            //printf("direction_a %d\n", tab->direction_a);
            //printf("operations_b %d\n", operations_b);
            //printf("direction_b %d\n", tab->direction_b);
            //printf("\n");
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
                //min_element = element;
                current->if_min_element = 1;
                tab->operations_a = operations_a;
                tab->operations_b = operations_b;
                tab->final_direction_a = tab->direction_a;
                tab->final_direction_b = tab->direction_b;
            }
            current = current->next;
        }
        //printf("Minimal cost element: %d\n", min_element);
        //printf("\n");
        moves_2(stack_a, stack_b, tab);
        push(stack_a, stack_b, 'b');
        //printing(*stack_a, *stack_b);
        current = *stack_a;
    }
    //stack_of_3(stack_a);
    //printf("tab_position: %d\n", tab->position);
    find_biggest_number(stack_b, tab);
    //printf("tab_position_2: %d\n", tab->position);
    while (if_sorted_from_biggest_to_smallest(stack_b) == 1)
    {
        if (tab->position < node_count_add(tab, stack_b) / 2)
		    shift_up(stack_b, 'b');
        else
            shift_down(stack_b, 'b');
    }
    //printing(*stack_a, *stack_b);
    while (*stack_b != NULL)
        push(stack_b, stack_a, 'a');
    //printf("Minimal cost element: %d\n", min_element);
    //to see what can be doe with moves function, why it doesn't work and also check if anything else has to be add to the struckt to reflect the direction of the further movements.
    //printing(*stack_a, *stack_b);
}