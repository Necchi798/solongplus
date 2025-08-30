/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:48:33 by gmezzini           #+#    #+#            */
/*   Updated: 2022/01/13 17:51:06 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ris_s1;
	unsigned char	*ris_s2;

	ris_s1 = (unsigned char *) s1;
	ris_s2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0 && i < n - 1)
		i++;
	return (ris_s1[i] - ris_s2[i]);
}
