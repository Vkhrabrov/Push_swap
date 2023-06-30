/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:59:00 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/06/30 23:58:31 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_tab(t_ps *tab)
{
	tab->i = 0;
	tab->b = 0;
	tab->k = 0;
	tab->position = 0;
	tab->direction_a = 0;
	tab->direction_b = 0;
	tab->operations_a = 0;
	tab->operations_b = 0;
}

void	initialize_list(t_list **stack)
{
	*stack = NULL;
}
/*void initialize_indexes(t_list **stack_a)
{
    t_list *current = *stack_a;

    while (current != NULL)
    {
        current->index = 0;
		current->content = 0;
		current->operations_a = 0;
		current->operations_b = 0;
		current->if_min_element = 0;
        current = current->next;
    }
}*/

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

	// stack_a = NULL;
	// stack_b = NULL;
	// tab = NULL;
	if (argc == 2)
		exit(error_msg("Error", 1));
	tab = (t_ps *)malloc(sizeof(t_ps));
	if (!tab)
		return (1);
	initialize_tab(tab);
	if (input_check(tab, argc, argv) == 1)
		exit(error_msg("Error", 1));
	initialize_list(&stack_a);
	initialize_list(&stack_b);
	filling_stack_a(tab, &stack_a, argc, argv);
	// initialize_indexes(&stack_a);
	indexing(&stack_a, argc, tab);
	// printing(stack_a, stack_b);
	node_count(tab, &stack_a, &stack_b);
	return (0);
}

int	input_check(t_ps *tab, int argc, char **argv)
{
	tab->i = 1;
	while (tab->i < argc)
	{
		tab->k = 0;
		if (argv[tab->i][tab->k] == '-' || argv[tab->i][tab->k] == '+')
			tab->k++;
		while (argv[tab->i][tab->k])
		{
			if (!ft_isdigit(argv[tab->i][tab->k]))
				exit(error_msg("Error", 1));
			tab->k++;
		}
		tab->b = ft_atoi(argv[tab->i]);
		if (tab->b > INT_MAX || tab->b < INT_MIN)
			exit(error_msg("Error", 1));
		tab->k = tab->i + 1;
		while (tab->k < argc)
		{
			if (tab->b == ft_atoi(argv[tab->k]))
				exit(error_msg("Error", 1));
			tab->k++;
		}
		tab->i++;
	}
	return (0);
}
