/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utilities_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:28:25 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/06/20 20:29:12 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_biggest_number(t_list **stack_a)
{
	t_list	*storage;
	t_list	*biggest_number;

	storage = *stack_a;
	biggest_number = *stack_a;
	while (storage && storage->next)
	{
		if ((biggest_number->index < storage->next->index))
			biggest_number = storage->next;
		storage = storage->next;
	}
	return (biggest_number);
}