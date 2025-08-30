/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_gen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:58:16 by gmezzini           #+#    #+#            */
/*   Updated: 2022/03/23 20:59:22 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_enemy	*last_enemy(t_enemy *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

t_enemy	*new_enemy(t_enemyytpe type, t_tile *tile)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (enemy == NULL)
	{
		ft_printf("\nErrorn\nErrore in new_enemy\n");
		return (0);
	}
	enemy->type = type;
	enemy->dir = 0;
	enemy->tile = tile;
	enemy->next = NULL;
	return (enemy);
}

void	add_enemy(t_game *game, t_enemyytpe type, t_tile *tile)
{
	t_enemy	*new;

	new = new_enemy(type, tile);
	if (new == NULL)
	{
		return ;
	}
	if (game->enemy_list == NULL)
		game->enemy_list = new;
	else
		last_enemy(game->enemy_list)->next = new;
}
