/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:24:42 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/07/10 23:38:57 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	filling_stack_a(t_ps *tab, t_list **stack_a, int argc, char **argv)
{
	int		value;
	t_list	*new_argument;

	tab->i = 1;
	while (tab->i < argc)
	{
		value = ft_atoi(argv[tab->i]);
		new_argument = (t_list *)malloc(sizeof(t_list));
		if (!new_argument)
		{
			free(tab);
			exit(error_msg("Error", 1));
		}
		new_argument->content = value;
		new_argument->next = NULL;
		ft_lstadd_back(stack_a, new_argument);
		tab->i++;
	}
}

int	find_closest_smaller(t_list **stack_b, t_ps *tab, int element)
{
	t_list	*closest_smaller;
	t_list	*current;

	closest_smaller = malloc(sizeof(t_list));
	if (!closest_smaller)
	{
		free(tab);
		exit(error_msg("Error", 1));
	}
	closest_smaller->index = INT_MIN;
	current = *stack_b;
	while (current != NULL)
	{
		if (element > (current)->index)
		{
			if (current->index > closest_smaller->index)
			{
				closest_smaller->index = current->index;
				tab->position = tab->i;
			}
		}
		current = current->next;
		tab->i++;
	}
	return (closest_smaller->index);
}

int	find_closest_bigger(t_list **stack_a, t_list **stack_b, t_ps *tab)
{
	t_list	*closest_bigger;
	t_list	*current;

	closest_bigger = malloc(sizeof(t_list));
	if (!closest_bigger)
		exit(EXIT_FAILURE);
	closest_bigger->index = INT_MAX;
	current = *stack_a;
	while (current != NULL)
	{
		if ((current)->index > (*stack_b)->index)
		{
			if ((current)->index < closest_bigger->index)
			{
				closest_bigger->index = current->index;
				tab->position = tab->i;
			}
		}
		current = current->next;
		tab->i++;
	}
	free(closest_bigger);
	return (tab->position);
}

int	if_sorted(t_list **stack_a)
{
	t_list	*storage;

	storage = *stack_a;
	while (storage && storage->next)
	{
		if (((storage)->content > storage->next->content))
			return (1);
		storage = (storage)->next;
	}
	return (0);
}

int	if_sorted_from_biggest_to_smallest(t_list **stack)
{
	t_list	*storage;

	storage = *stack;
	while (storage && storage->next)
	{
		if (((storage)->index < storage->next->index))
			return (1);
		storage = (storage)->next;
	}
	return (0);
}
