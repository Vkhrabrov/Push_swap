/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:11:20 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/06/02 21:36:56 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
