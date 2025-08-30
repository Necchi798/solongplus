/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:03:01 by gmezzini           #+#    #+#            */
/*   Updated: 2022/01/18 17:38:59 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_wrd(char const *s, char c)
{
	int	i;
	int	ris;

	i = 0;
	ris = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') == 1
			&& (s[i] == c || s[i] == '\0') == 0)
			ris++;
		i++;
	}
	return (ris);
}

static char	*wrd_up(const char *src, int start, int finish)
{
	char	*cpy;
	size_t	i;

	i = 0;
	cpy = ft_calloc((finish - start + 1), sizeof (char));
	if (cpy == NULL)
		return (NULL);
	while (start < finish)
		cpy[i++] = src[start++];
	return (cpy);
}

char	**ft_split(char const *s, char c)
{
	int		flag;
	size_t	i;
	size_t	j;
	char	**s_str;

	if (!s)
		return (NULL);
	s_str = ft_calloc((count_wrd(s, c) + 1), sizeof(char *));
	if (s_str == NULL || s == NULL)
		return (NULL);
	j = 0;
	i = 0;
	flag = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && flag < 0)
			flag = i;
		else if ((s[i] == c || i == ft_strlen(s)) && flag >= 0)
		{
			s_str[j++] = wrd_up(s, flag, i);
			flag = -1;
		}
		i++;
	}
	return (s_str);
}
