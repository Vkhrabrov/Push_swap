/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vadimhrabrov <vadimhrabrov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:38:57 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/06/18 13:26:21 by vadimhrabro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*a;

	a = malloc(sizeof(t_list));
	if (!a)
		return (a);
	(*a).content = *(int*)content;
	(*a).next = (t_list *)(void *)0;
	return (a);
}

/*int	main(void)
{
	char *str = "Hello World!";
	t_list *b = ft_lstnew(str);
	printf("1: %s\n", b->content);
	printf("2: %p\n", &(b->content));
	return(0);
}*/	
