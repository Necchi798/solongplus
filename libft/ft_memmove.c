/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:25:53 by gmezzini           #+#    #+#            */
/*   Updated: 2022/01/17 10:32:00 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, unsigned int n)
{
	int		i;
	char	*p_dst;
	char	*p_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	p_dst = (char *) dst;
	p_src = (char *) src;
	if (dst >= src)
	{
		i = (int) n;
		while (i--)
			p_dst[i] = p_src[i];
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
