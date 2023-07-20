/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:59:00 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/07/21 00:37:55 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_tab(t_ps *tab)
{
	tab->i = 0;
	tab->b = 0;
	tab->k = 0;
	tab->t = 0;
	tab->position = 0;
	tab->direction_a = 0;
	tab->direction_b = 0;
	tab->final_direction_a = 0;
	tab->final_direction_b = 0;
	tab->operations_a = 0;
	tab->operations_b = 0;
	tab->operations_a_add = 0;
	tab->operations_b_add = 0;
	tab->min_operations = 0;
	tab->total_operations = 0;
}

void	initialize_list(t_list **stack)
{
	*stack = NULL;
}

int	error_msg(char *first, int ret)
{
	size_t	len;

	if (!first)
		len = 0;
	else
		len = ft_strlen(first);
	write(2, first, len);
	write(2, "\n", 1);
	return (ret);
}

int	main(int argc, char **argv)
{
	t_ps	*tab;
	t_list	*stack_a;
	t_list	*stack_b;
	char	**argv_add;

	argv_add = NULL;
	tab = (t_ps *)malloc(sizeof(t_ps));
	if (!tab)
		return (1);
	initialize_tab(tab);
	process_input(tab, &argc, &argv, argv_add); 
	initialize_list(&stack_a);
	initialize_list(&stack_b);
	filling_stack_a(tab, &stack_a, argc, argv);
	indexing(&stack_a, argc, tab);
	if (if_sorted(&stack_a) == 1)
		node_count(tab, &stack_a, &stack_b);
	free(tab);
	free_list(stack_a);
	if (tab->t == 1)
		free_array(argv, tab);
	return (0);
}

int	input_check(t_ps *tab, int argc, char **argv)
{
	if (tab->t == 1)
		tab->i = 0;
	else 
		tab->i = 1;
	while (tab->i < argc)
	{
		check_input(tab, argc, argv, tab->i);
		tab->i++;
	}
	return (0);
}
