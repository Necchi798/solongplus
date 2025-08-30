/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:55:14 by gmezzini           #+#    #+#            */
/*   Updated: 2022/03/23 20:38:14 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	ft_chartable_linecount(char **table)
{
	int	count;

	count = 0;
	while (table[count])
		count++;
	return (count);
}

t_bool	check_cep(t_mapcheckerdata data)
{
	t_bool	valid;

	valid = TRUE;
	if (!data.b_player || !data.b_exit || !data.b_collect)
	{
		ft_printf("Error\nDevono essserci 'P' and 'E'e almeno una 'C'\n");
		valid = FALSE;
	}
	return (valid);
}

int	valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P'
		|| c == 'H' || c == 'V' || c == 'U')
		return (TRUE);
	return (FALSE);
}

int	valid_uniquechar(char c, char checker, t_bool *bool)
{
	if (c == checker && *bool == FALSE)
		*bool = TRUE;
	else if (c == checker && *bool == TRUE)
		return (FALSE);
	return (TRUE);
}

int	valid_border(char c, t_vector point, t_vector size)
{
	if (point.y == 0 || point.x == 0
		|| point.y == size.y - 1 || point.x == size.x - 1)
		if (c != '1')
			return (FALSE);
	return (TRUE);
}
