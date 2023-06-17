/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:45:22 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/06/17 23:22:45 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *find_biggest_number(t_list **stack_a)
{
    t_list *storage = *stack_a;
    t_list *biggest_number = *stack_a;

    while (storage && storage->next)
    {
        if ((biggest_number->index < storage->next->index))
            biggest_number = storage->next;
        storage = storage->next;
    }
    return (biggest_number);
}


t_list *find_smallest_number(t_list **stack_a)
{
    t_list *storage = *stack_a;
    t_list *smallest_number = *stack_a;

    while (storage && storage->next)
    {
        if ((storage->index > storage->next->index))
            smallest_number = storage->next;
        storage = (storage)->next;
    }
    return (smallest_number);
}

int if_sorted(t_list **stack_a)
{
    t_list *storage = *stack_a;

    while (storage && storage->next)
    {
        if (((storage)->content > storage->next->content))
            return 1;
        storage = (storage)->next;
    }
    return 0;
}

void stack_of_3(t_list **stack_a)
{
    t_list *last;
    t_list *temp;

    temp = (*stack_a)->next;
    last = *stack_a;
    
    if (if_sorted(stack_a) == 1)
    {
        if (*stack_a == find_biggest_number(stack_a))
        {
            shift_up(stack_a, 'a');
        }
        else if ((*stack_a)->next == find_biggest_number(stack_a))
            shift_down(stack_a, 'a');
        if (if_sorted(stack_a) == 1)
            swap(stack_a, 'a');
    }
}

int node_count_add(t_ps *tab, t_list **stack)
{
    t_list *temp = *stack;
    tab->i = 0;
    while (temp != NULL)
    {
        tab->i++;
        temp = temp->next;
    }
    return (tab->i);
}


void stack_of_5(t_list **stack_a, t_list **stack_b, t_ps *tab)
{
    t_list *closest_bigger;
    t_list *current;
    int     position;

    tab->i = 0;
    tab->b = 0;
    position = 1;
    closest_bigger = NULL;
    current = *stack_a;
    closest_bigger = malloc(sizeof(t_list));
    closest_bigger->index = INT_MAX;
    if (if_sorted(stack_a) == 1)
    {
        push(stack_a, stack_b, 'b');
        push(stack_a, stack_b, 'b');
        stack_of_3(stack_a);
    }
    /*push(stack_b, stack_a, 'a');*/
    printing(*stack_a, *stack_b);
    if (*stack_b)
    {
        current = *stack_a;
        tab->i = 0;
        tab->b = 0;
    }
    while (current != NULL)
    {
        printf("(current)->index %d\n", (current)->index);
        printf("closest_bigger->index %d\n", closest_bigger->index);
        if ((current)->index > (*stack_b)->index)
        {
            if ((current)->index < closest_bigger->index)
                closest_bigger->index = current->index;
        }
        current = current->next;
        tab->i++;
    }
printf("tab->i %d\n", tab->i);
if (closest_bigger->index == INT_MAX)
{
    push(stack_b, stack_a, 'a');
    printing(*stack_a, *stack_b);
}
else
{
    if (tab->i > (node_count_add(tab, stack_a))/2)
    {
        while (tab->b < (node_count_add(tab, stack_a) - tab->i + 1))
        {
            shift_down(stack_a, 'a');
            printing(*stack_a, *stack_b);
            tab->b++;
        }
    }
    else 
    {
        while (tab->b < node_count_add(tab, stack_a) - tab->i + 1)
        {
            shift_up(stack_a, 'a');
            tab->b++;
        }
    }
    push(stack_b, stack_a, 'a');
    printing(*stack_a, *stack_b);
}
    
    if (if_sorted(stack_a) == 1)
            shift_up(stack_a, 'a');
    push(stack_b, stack_a, 'a');
    printf("last print\n");
    printing(*stack_a, *stack_b);
}

void node_count(t_ps *tab, t_list **stack_a, t_list **stack_b)
{
    t_list *temp;

    (void)stack_b;
    tab->i = 0;
    temp = *stack_a;
    while (*stack_a != NULL)
    {
        tab->i++;
        *stack_a = (*stack_a)->next;
    }
    *stack_a = temp; // Resetting stack_a pointer to the beginning
    if (tab->i <= 3)
    {
        printing(*stack_a, *stack_b);
        stack_of_3(stack_a);
        printing(*stack_a, *stack_b);
    }
    else if (tab->i > 3 && tab->i <= 5)
        stack_of_5(stack_a, stack_b, tab);
    /*else if (tab->i == 100)
        stack_of_100(tab, stack_a, stack_b);
    else
        stack_of_100(tab, stack_a, stack_b);*/
}
