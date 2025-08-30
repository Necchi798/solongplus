/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:54:27 by gmezzini           #+#    #+#            */
/*   Updated: 2022/01/11 14:23:13 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void) s);
}
