/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:33:01 by gmezzini           #+#    #+#            */
/*   Updated: 2022/01/16 21:05:13 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	j;
	size_t	slen;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc (1, 1));
	slen = ft_strlen(s);
	if (slen > len)
		slen = len;
	sub_str = (char *) malloc(sizeof(char) * (slen + 1));
	if (!sub_str)
		return (NULL);
	i = start;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			sub_str[j++] = s[i];
		i++;
	}
	sub_str[j] = '\0';
	return (sub_str);
}
