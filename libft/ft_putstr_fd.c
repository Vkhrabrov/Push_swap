/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:42:22 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/02/07 20:44:37 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
