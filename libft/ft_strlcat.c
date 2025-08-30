/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:28:27 by gmezzini           #+#    #+#            */
/*   Updated: 2022/01/13 17:42:08 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	l_src;
	size_t	l_dst;

	l_src = ft_strlen(src);
	l_dst = ft_strlen(dst);
	i = 0;
	j = l_dst;
	if (l_dst < dstsize - 1 && dstsize > 0)
	{
		while (src[i] && l_dst + i < dstsize - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (l_dst >= dstsize)
		l_dst = dstsize;
	return (l_dst + l_src);
}
