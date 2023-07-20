/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utilities_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:48:31 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/07/21 00:47:45 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *head)
{
	t_list	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	free_array(char **array, t_ps *tab)
{
	int	d;

	d = 0;
	if (tab->t == 1)
	{
		while (array[d]) 
		{
			free(array[d]);
			d++;
		}
		free(array);
	}
}

void	safe_exit(t_ps *tab)
{
	free(tab);
	exit(error_msg("Error", 1));
}

void	process_input(t_ps *tab, int *argc, char ***argv, char **argv_add)
{
	int	i;

	i = 0;
	if (*argc == 2 && ft_strlen((*argv)[1]) > 1)
	{
		argv_add = ft_split((*argv)[1], ' ');
		while (argv_add[i] != NULL)
			i++;
		*argv = argv_add;
		*argc = i;
		tab->t = 1;
	}
	input_check(tab, *argc, *argv); 
	if (*argc < 3)
	{
		if (*argc == 2)
		{
			if (ft_strlen((*argv)[1]) == 1)
				exit(1);
			else 
				exit(error_msg("Error", 1));
		}
		else
			exit(error_msg("Error", 1));
	}
}

void	check_input(t_ps *tab, int argc, char **argv, int i)
{
	tab->k = 0;
	if ((argv[i][tab->k] == '-' || argv[i][tab->k] == '+') 
			&& ft_strlen(argv[i]) == 1)
		safe_exit(tab);
	if (argv[i][tab->k] == '-' || argv[i][tab->k] == '+')
		tab->k++;
	while (argv[i][tab->k])
	{
		if (!ft_isdigit(argv[i][tab->k]))
			safe_exit(tab);
		tab->k++;
	}
	tab->b = ft_atoi(argv[i]);
	if (tab->b > INT_MAX || tab->b < INT_MIN)
		safe_exit(tab);
	tab->k = i + 1;
	while (tab->k < argc)
	{
		if (tab->b == ft_atoi(argv[tab->k]))
			safe_exit(tab);
		tab->k++;
	}
}
