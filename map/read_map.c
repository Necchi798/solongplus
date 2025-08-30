/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:47:19 by gmezzini           #+#    #+#            */
/*   Updated: 2022/03/25 17:09:53 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "../gnl/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int	check_newline(char *line)
{
	int	i;

	i = 1;
	if (line[0] == '\n')
	{
		ft_printf("Error\nformato non valido");
		return (0);
	}
	while (line[i])
	{
		if (line[i] == '\n' && line[i - 1] == '\n')
		{
			ft_printf("Error\nformato non valido");
			return (0);
		}
		i++;
	}
	if (line[i - 1] == '\n')
	{
		ft_printf("Error\nformato non valido");
		return (0);
	}
	return (1);
}

static int	check_extension(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[--i] == 'r')
		if (file[--i] == 'e')
			if (file[--i] == 'b')
				if (file[--i] == '.')
					return (1);
	ft_printf("Error\nestensione non valida");
	return (FALSE);
}

char	**read_map(char *file)
{
	char	*line;
	char	*map;
	int		fd;
	char	**toret;

	if (!check_extension(file))
		return (NULL);
	map = ft_calloc(1, 1);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map = ft_strjoin(map, line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!check_newline(map))
	{
		free(map);
		return (NULL);
	}
	toret = ft_split(map, '\n');
	free(map);
	return (toret);
}
