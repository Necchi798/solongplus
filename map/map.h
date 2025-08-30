/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:53:07 by gmezzini           #+#    #+#            */
/*   Updated: 2022/03/23 20:26:18 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../basics.h"
# include "../so_long.h"

typedef struct s_mapcheckerdata
{
	t_vector	size;
	t_vector	point;
	t_bool		b_player;
	t_bool		b_exit;
	t_bool		b_collect;
}				t_mapcheckerdata;

char	**read_map(char *file);
int		valid_map(char **map);
void	add_enemy(t_game *game, t_enemyytpe type, t_tile *tile);

#endif