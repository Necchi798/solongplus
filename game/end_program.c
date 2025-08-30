/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:47:51 by gmezzini           #+#    #+#            */
/*   Updated: 2022/03/25 16:49:02 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_tilemap(t_game *game)
{
	t_tile	**tilemap;

	tilemap = game->tilemap;
	while (*game->tilemap != NULL)
	{
		free(*game->tilemap);
		game->tilemap++;
	}
	free (tilemap);
}

void	free_enemies(t_game *game)
{
	t_enemy	*next;

	if (game->enemy_list == NULL)
		return ;
	while (TRUE)
	{
		next = game->enemy_list->next;
		free (game->enemy_list);
		if (next == NULL)
			break ;
		game->enemy_list = next;
	}
}

int	end_program(t_game *game)
{
	free_tilemap(game);
	game->tilemap = NULL;
	free_enemies(game);
	game->enemy_list = NULL;
	exit(0);
}

void	kill_player(t_game *game)
{
	game->player.tile = NULL;
	game->status = -1;
}
