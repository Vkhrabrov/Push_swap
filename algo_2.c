/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vadimhrabrov <vadimhrabrov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:31:39 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/07/09 18:15:00 by vadimhrabro      ###   ########.fr       */
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

int distance_from_bottom(t_list **stack, int element) 
{
    int distance = 0;
    t_list *current = *stack;
    while (current != NULL && current->index != element)
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
    int top_distance = distance_from_top(stack, tab);
    int bottom_distance = distance_from_bottom(stack, biggest);
    if (top_distance < bottom_distance)
    {
        tab->direction_b = 1;
        return top_distance;
    }
    else
    {
        tab->direction_b = 0;
        return bottom_distance;
    }
}

int find_inser_position_add(int distance_from_top, int dist_from_bottom, t_ps *tab)
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

int find_insert_position(t_list **stack, t_ps *tab, int element) 
{
    int     distance_from_top;
    t_list  *current;
    int     dist_from_bottom;
    int     closest_smaller;

    distance_from_top = 0;
    dist_from_bottom = 0;
    current = *stack;
    closest_smaller = find_closest_smaller(&current, tab, element);
    if (current == NULL) 
        return distance_from_top;
    while (current != NULL && current->index != closest_smaller) 
    { 
        if(closest_smaller == INT_MIN)
            return (distance_to_biggest(stack, tab));
        distance_from_top++;
        current = current->next;
    }
    if (dist_from_bottom == 0)
        dist_from_bottom = node_count_add(tab, stack) - distance_from_top;
    return (find_inser_position_add (distance_from_top, dist_from_bottom, tab));
}

int	ft_find_shortest_distance(t_list **stack, t_ps *tab, int element)
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

void    moves_2_add(t_list **stack_a, t_list **stack_b, t_ps *tab)
{
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
}

void    moves_2(t_list **stack_a, t_list **stack_b, t_ps *tab)
{
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
        moves_2_add(stack_a, stack_b, tab);
}

void minimal_element_calculations(t_ps *tab)
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
            if(tab->total_operations < tab->min_operations) 
            {
                tab->min_operations = tab->total_operations;
                tab->operations_a = tab->operations_a_add;
                tab->operations_b = tab->operations_b_add;
                tab->final_direction_a = tab->direction_a;
                tab->final_direction_b = tab->direction_b;
            }
}

void end_of_function_100(t_list **stack_a, t_list **stack_b, t_ps *tab)
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
    t_list *current;
    
    push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
    current = *stack_a;
    int element;

    element = 0;
    while (node_count_add(tab, stack_a) > 0)
    {
        tab->min_operations = INT_MAX;
        while(current) 
        {
            element = current->index;
            tab->operations_a_add = ft_find_shortest_distance(stack_a, tab, element);
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