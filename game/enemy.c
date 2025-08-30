/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:34:55 by gmezzini           #+#    #+#            */
/*   Updated: 2022/03/25 16:44:39 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	kill_player(t_game *game);

void	move_enemy_to(t_enemy *enemy, t_tile *tile)
{
	enemy->tile->type = EMPTY;
	tile->type = ENEMY;
	enemy->tile = tile;
}

t_bool	change_dir(t_enemy *enemy)
{
	if (enemy->dir == 0)
		enemy->dir = 1;
	else
		enemy->dir = 0;
	return (FALSE);
}

t_bool	move_ver(t_enemy *enemy, t_game *game)
{
	if (enemy->dir == 0)
	{
		if (enemy->tile->up->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->up);
		else if (enemy->tile->up->type == PLAYER)
		{
			kill_player(game);
			move_enemy_to(enemy, enemy->tile->up);
		}
		else
			return (change_dir(enemy));
	}
	else if (enemy-> dir == 1)
	{
		if (enemy->tile->down->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->down);
		else if (enemy->tile->down->type == PLAYER)
		{
			kill_player(game);
			move_enemy_to(enemy, enemy->tile->down);
		}
		else
			return (change_dir(enemy));
	}
	return (TRUE);
}

t_bool	move_hor(t_enemy *enemy, t_game *game)
{
	if (enemy->dir == 0)
	{
		if (enemy->tile->left->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->left);
		else if (enemy->tile->left->type == PLAYER)
		{
			kill_player(game);
			move_enemy_to(enemy, enemy->tile->left);
		}
		else
			return (change_dir(enemy));
	}
	else if (enemy-> dir == 1)
	{
		if (enemy->tile->right->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->right);
		else if (enemy->tile->right->type == PLAYER)
		{
			kill_player(game);
			move_enemy_to(enemy, enemy->tile->right);
		}
		else
			return (change_dir(enemy));
	}
	return (TRUE);
}

void	move_enemies(t_game *game)
{
	t_enemy	*current;

	if (game->enemy_list == NULL)
		return ;
	current = game->enemy_list;
	while (TRUE)
	{
		if (current->type == HORIZONTAL_ENEM)
			move_hor(current, game);
		else if (current->type == VERTICAL_ENEM)
			move_ver(current, game);
		if (current->next == NULL)
			break ;
		current = current->next;
	}
}
