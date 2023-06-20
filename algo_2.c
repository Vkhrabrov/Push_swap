/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:31:39 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/06/20 22:23:52 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_of_100(t_list **stack_a, t_list **stack_b, t_ps *tab)
{
    t_list  *pivot;
    t_list  *current;

    (void)tab;
    tab->i = 0;
    current = *stack_a;
    if (if_sorted(stack_a) == 1)
    {
        push(stack_a, stack_b, 'b');
        pivot = *stack_b;
        while (tab->i < 100)
        {
            if (current->index > pivot->index)
                push(stack_a, stack_b, 'b');
            else 
                shift_up(stack_a, 'a');
            tab->i++;
        }
    }
    printing(*stack_a, *stack_b);
}