/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:37:15 by gmezzini           #+#    #+#            */
/*   Updated: 2022/01/19 12:53:41 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (!fd || !s)
		return ;
	i = 0;
	while (s[i] != 0)
		i++;
	write(fd, s, i);
	write(fd, "\n", 1);
}
