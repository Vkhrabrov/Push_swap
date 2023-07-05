/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utilities_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vadimhrabrov <vadimhrabrov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:28:25 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/07/05 23:14:24 by vadimhrabro      ###   ########.fr       */
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