/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:38:41 by gmezzini           #+#    #+#            */
/*   Updated: 2022/01/13 16:49:47 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_str;
	unsigned char	*s2_str;

	s1_str = (unsigned char *)s1;
	s2_str = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (s1_str[i] != s2_str[i])
			return (s1_str[i] - s2_str[i]);
		i++;
	}
	return (0);
}
