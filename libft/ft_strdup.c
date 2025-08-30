/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:42:48 by gmezzini           #+#    #+#            */
/*   Updated: 2022/01/15 18:17:21 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strdup(const char *src)
{
	int		len;
	char	*cpy;

	len = ft_strlen(src) + 1;
	cpy = (char *) malloc(sizeof (char) * len);
	if (cpy == NULL)
		return (NULL);
	ft_strcpy(cpy, (char *) src);
	return (cpy);
}
