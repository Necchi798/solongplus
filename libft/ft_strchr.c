/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:25:52 by gmezzini           #+#    #+#            */
/*   Updated: 2022/01/16 04:35:37 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	while ((*s != '\0') && (*s != ch))
	{
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return ((char *) NULL);
}
