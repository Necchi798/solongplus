/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:57:16 by gmezzini           #+#    #+#            */
/*   Updated: 2022/03/25 16:55:49 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdio.h>

int		ft_chartable_linecount(char **table);
int		valid_char(char c);
int		valid_uniquechar(char c, char checker, t_bool *bool);
int		valid_border(char c, t_vector point, t_vector size);
t_bool	check_cep(t_mapcheckerdata data);

static t_mapcheckerdata	init_checkerdata(char **map)
{
	t_mapcheckerdata	data;

	data.size.x = ft_strlen(map[0]);
	data.size.y = ft_chartable_linecount(map);
	data.b_player = FALSE;
	data.b_exit = FALSE;
	data.b_collect = FALSE;
	data.point.y = 0;
	data.point.x = 0;
	return (data);
}

static int	checks(char **map, t_mapcheckerdata *data)
{
	int	x;
	int	y;

	x = data->point.x;
	y = data->point.y;
	if (!valid_char(map[y][x]))
	{
		ft_printf("Error\nCaratteri non validi all'interno della mappa\n");
		return (FALSE);
	}
	if (!valid_uniquechar(map[y][x], 'P', &data->b_player))
	{
		ft_printf("Error\nDeve esserci solo una P\n");
		return (FALSE);
	}
	if (map[y][x] == 'E')
		data->b_exit = TRUE;
	if (!valid_border(map[y][x], data->point, data->size))
	{
		ft_printf("Error\nLa mappa deve essere circondata da 1\n");
		return (FALSE);
	}
	if (map[y][x] == 'C')
		data->b_collect = TRUE;
	return (TRUE);
}

int	valid_map(char **map)
{
	t_mapcheckerdata	data;
	t_bool				valid;

	data = init_checkerdata(map);
	valid = TRUE;
	while (map[data.point.y])
	{
		if ((int) ft_strlen(map[data.point.y]) != data.size.x)
		{
			ft_printf("Error\nMappa non rettangolare\n");
			return (FALSE);
		}
		data.point.x = 0;
		while (map[data.point.y][data.point.x])
		{
			if (checks(map, &data) == FALSE)
				return (FALSE);
			data.point.x++;
		}
		data.point.y++;
	}
	valid = check_cep(data);
	return (valid);
}
