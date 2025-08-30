/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:21:11 by gmezzini           #+#    #+#            */
/*   Updated: 2022/01/15 16:48:56 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nb;

	nb = (long) n;
	i = len(nb);
	str = ft_calloc((i-- + 1), sizeof (char));
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		str[0] = '-';
	}
	while (nb > 0)
	{
		str[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}
