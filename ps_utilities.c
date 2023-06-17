/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:24:42 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/06/09 21:27:18 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	filling_stack_a(t_ps *tab, t_list **stack_a, int argc, char **argv)
{
	t_list	*new_argument;
	int		value;

	tab->i = 1;
	while (tab->i < argc)
	{
		value = ft_atoi(argv[tab->i]);
		new_argument = (t_list *)malloc(sizeof(t_list));
		if (!new_argument)
			exit(error_msg("Error", 1));
		new_argument->content = value;
		new_argument->next = NULL;
		ft_lstadd_back(stack_a, new_argument);
		tab->i++;
	}
}

/*void testing_grounds(t_ps *tab, t_list *stack_a, t_list *stack_b)
{
	(void)tab;

	push(&stack_a, &stack_b, 'b');
	push(&stack_a, &stack_b, 'b');
	push(&stack_a, &stack_b, 'b');
	swap(&stack_a, 'a');
	swap(&stack_b, 'b');
	s_swap(&stack_a, &stack_b);
	shift_up(&stack_a, 'a');
	shift_up(&stack_b, 'b');
	rr_shift_up(&stack_a, &stack_b);
	rr_shift_down(&stack_a, &stack_b);
	shift_down(&stack_a, 'a');
	shift_down(&stack_b, 'b');
}*/

void printing(t_list *stack_a, t_list *stack_b)
{
	write(1, "\n", 1);
	t_list *temp_a = stack_a;
    t_list *temp_b = stack_b;
	if (temp_a != NULL && temp_b != NULL)
	{
    	while (temp_a != NULL && temp_b != NULL)
    	{
        	printf("stack a index: %i   stack b index: %i\n", temp_a->index, temp_b->index);
        	temp_a = temp_a->next;
        	temp_b = temp_b->next;
    	}
	}
	if (temp_b == NULL)
	{
		while (temp_a != NULL)
		{
			printf("stack a index: %i\n", temp_a->index);
			temp_a = temp_a->next;
		}
	}
	if (temp_a == NULL)
	{
		while (temp_b != NULL)
		{
			printf("\t\t   stack b index: %i\n", temp_b->index);
			temp_b = temp_b->next;
		}
	}
}

void	indexing(t_list **stack_a, int argc, t_ps *tab)
{
	t_list *current;
	t_list *min_node;
	int min;

	current = *stack_a;
	tab->i = 1;
	while (tab->i <= argc - 1)
	{
		min = INT_MAX;
		while(current)
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
