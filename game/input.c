/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:24:10 by gmezzini           #+#    #+#            */
/*   Updated: 2022/03/25 16:45:19 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_enemies(t_game *game);
void	kill_player(t_game *game);

void	move_right(t_game *game)
{
	game->player.direction = RIGHT;

	if (game->player.tile->right->type == COLLECTABLE){
		game->points++;
		game->collects--;
	}
	if (game->player.tile->right->type == EXIT && game->collects == 0)
		game->status = 1;
	if (game->player.tile->right->type == ENEMY)
	{
		kill_player(game);
		return ;
	}
	if (game->player.tile->right->type != WALL
		&& game->player.tile->right->type != EXIT && game->player.tile->right->type != IND_WALL)
	{
		game->moves++;
		game->player.tile->right->type = PLAYER;
		game->player.tile->type = EMPTY;
		game->player.tile = game->player.tile->right;
		
		// move_enemies(game);
	}
}

void	move_left(t_game *game)
{
	game->player.direction = LEFT;

	if (game->player.tile->left->type == COLLECTABLE){
		game->collects--;
		game->points++;

	}
	else if (game->player.tile->left->type == EXIT && game->collects == 0)
		game->status = 1;
	else if (game->player.tile->left->type == ENEMY)
	{
		kill_player(game);
		return ;
	}
	if ((game->player.tile->left->type != WALL)
		&& game->player.tile->left->type != EXIT &&  game->player.tile->left->type != IND_WALL)
	{
		game->moves++;
		game->player.tile->left->type = PLAYER;
		game->player.tile->type = EMPTY;
		game->player.tile = game->player.tile->left;
		
		// move_enemies(game);
	}
}

void	move_up(t_game *game)
{	
	game->player.direction = UP;
	if (game->player.tile->up->type == COLLECTABLE){
		game->collects--;
		game->points++;

	}
	if (game->player.tile->up->type == EXIT && game->collects == 0)
		game->status = 1;
	if (game->player.tile->up->type == ENEMY)
	{
		kill_player(game);
		return ;
	}
	if ((game->player.tile->up->type != WALL &&  game->player.tile->up->type != IND_WALL)
		&& game->player.tile->up->type != EXIT)
	{
		game->moves++;
		game->player.tile->up->type = PLAYER;
		game->player.tile->type = EMPTY;
		game->player.tile = game->player.tile->up;
		
		// move_enemies(game);
	}
}

void	move_down(t_game *game)
{
	game->player.direction = DOWN;
	if (game->player.tile->down->type == COLLECTABLE){
		game->collects--;
		game->points++;

	}
	if (game->player.tile->down->type == EXIT && game->collects == 0)
		game->status = 1;
	if (game->player.tile->down->type == ENEMY)
	{
		kill_player(game);
		return ;
	}
	if (game->player.tile->down->type != WALL
		&& game->player.tile->down->type != EXIT &&  game->player.tile->down->type != IND_WALL)
	{
		game->moves++;
		game->player.tile->down->type = PLAYER;
		game->player.tile->type = EMPTY;
		game->player.tile = game->player.tile->down;
		// move_enemies(game);
	}
}

void breakWall(t_game * game){
	
	if (game->player.direction == UP && game->player.tile->up->type == WALL )
	{
		game->player.tile->up->type = EMPTY;
	}
	else if (game->player.direction == DOWN && game->player.tile->down->type == WALL)
	{
		game->player.tile->down->type = EMPTY;
	}
	else if (game->player.direction == LEFT && game->player.tile->left->type == WALL)
	{
		game->player.tile->left->type = EMPTY;
	}
	else if (game->player.direction == RIGHT && game->player.tile->right->type == WALL)
	{
		game->player.tile->right->type = EMPTY;
	}
	
	
}

int	input(int key, t_game *game)
{	
	if(key == 32)
		breakWall(game);
	if (key == 100 && game->status == 0)
		move_right(game);
	else if (key == 97 && game->status == 0)
		move_left(game);
	else if (key == 119 && game->status == 0)
		move_up(game);
	else if (key == 115 && game->status == 0)
		move_down(game);
	else if (key == 65307 )
		end_program(game);
	return (0);
}
