/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:13:54 by gmezzini           #+#    #+#            */
/*   Updated: 2022/01/17 13:39:21 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *) malloc (sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j] = (char) s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
		str[j++] = (char) s2[i++];
	str[j] = '\0';
	free(s1);
	free(s2);
	return (str);
}
