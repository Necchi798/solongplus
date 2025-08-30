/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:17:47 by gmezzini           #+#    #+#            */
/*   Updated: 2022/03/25 16:29:10 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_text(t_game *game);


static void	player_animation(t_player *player)
{

	if (player->framecount == 0)
		player->current_img = player->idle_img_0;
	else if (player->framecount == player->idle_frames)
		player->current_img = player->idle_img_1;
	else if (player->framecount == player->idle_frames * 2)
		player->current_img = player->idle_img_2;
	else if (player->framecount == player->idle_frames * 3)
		player->current_img = player->idle_img_3;
	else if (player->framecount == player->idle_frames * 4)
		player->current_img = player->idle_img_4;
	else if (player->framecount == player->idle_frames * 5)
		player->current_img = player->idle_img_5;
	else if (player->framecount == player->idle_frames * 6)
		player->current_img = player->idle_img_6;
	else if (player->framecount == player->idle_frames * 8)
	{
		player->current_img = player->idle_img_7;
		player->framecount = 0;
	}
	player->framecount += 1;
}

static void	door_animation_closed(t_door *door_close_img)
{
	if (door_close_img->framecount == 0)
		door_close_img->current_img = door_close_img->idle_img_0;
	else if (door_close_img->framecount == door_close_img->idle_frames)
		door_close_img->current_img = door_close_img->idle_img_1;
	else if (door_close_img->framecount == door_close_img->idle_frames * 2)
		door_close_img->current_img = door_close_img->idle_img_0;
	else if (door_close_img->framecount == door_close_img->idle_frames * 3)
		door_close_img->current_img = door_close_img->idle_img_3;
	else if (door_close_img->framecount == door_close_img->idle_frames * 4)
		door_close_img->current_img = door_close_img->idle_img_4;
	else if (door_close_img->framecount == door_close_img->idle_frames * 5)
		door_close_img->current_img = door_close_img->idle_img_5;
	else if (door_close_img->framecount == door_close_img->idle_frames * 6)
		door_close_img->current_img = door_close_img->idle_img_6;
	else if (door_close_img->framecount == door_close_img->idle_frames * 7)
	{
		door_close_img->current_img = door_close_img->idle_img_7;
		door_close_img->framecount = 0;
	}
	door_close_img->framecount += 1;
}

static void	door_animation_opened(t_door *door_open_img)
{
	if (door_open_img->framecount == 0)
		door_open_img->current_img = door_open_img->idle_img_0;
	else if (door_open_img->framecount == door_open_img->idle_frames)
		door_open_img->current_img = door_open_img->idle_img_1;
	else if (door_open_img->framecount == door_open_img->idle_frames * 2)
		door_open_img->current_img = door_open_img->idle_img_2;
	else if (door_open_img->framecount == door_open_img->idle_frames * 3)
		door_open_img->current_img = door_open_img->idle_img_3;
	else if (door_open_img->framecount == door_open_img->idle_frames * 4)
		door_open_img->current_img = door_open_img->idle_img_4;
	else if (door_open_img->framecount == door_open_img->idle_frames * 5)
		door_open_img->current_img = door_open_img->idle_img_5;
	else if (door_open_img->framecount == door_open_img->idle_frames * 6)
		door_open_img->current_img = door_open_img->idle_img_6;
	else if (door_open_img->framecount == door_open_img->idle_frames * 7)
	{
		door_open_img->current_img = door_open_img->idle_img_7;
		door_open_img->framecount = 0;
	}
	door_open_img->framecount += 1;
}

static void	enemy_animation(t_enemy_img *img)
{
	if (img->basic_framecount == img->basic_idle_frame)
		img->basic_current = img->basic_0;
	else if (img->basic_framecount == img->basic_idle_frame * 2)
		img->basic_current = img->basic_1;
	else if (img->basic_framecount == img->basic_idle_frame * 3)
	{
		img->basic_current = img->basic_2;
		img->basic_framecount = 0;
	}
	img->basic_framecount += 1;
}

int	update(t_game *game)
{

	if (game->collects > 0)
		door_animation_closed(&game->door_close_img);
	else
		door_animation_opened(&game->door_open_img);
	player_animation(&game->player);
	enemy_animation(&game->enemy_imgs);
	render(*game);
	draw_text(game);
	return (1);
}
