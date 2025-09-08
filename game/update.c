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
void	move_enemies(t_game *game);
#include <time.h> 
double get_time() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (double)ts.tv_sec + (double)ts.tv_nsec / 1e9; // 1e9 = 1 miliardo
}
const int TOTALE_FRAME = 4;
const double DURATA_FRAME = 0.2; // Ogni frame dura 0.2 secondi

static void	player_animation(t_player *player)
{
	static int frame_corrente=0;
	static double timer_frame = 0.0;
	static double then = 0;
	if(then == 0)
		then = get_time();
	double now = get_time();
	double dt = now - then;
	timer_frame += dt;
	if(timer_frame >= 0.05){
		timer_frame -= 0.05;
		player->current_img = player->frames[(frame_corrente + 1) % 8];
		frame_corrente++;
	}	
	then = now;
	// if (player->framecount == 0)
	// 	player->current_img = player->idle_img_0;
	// else if (player->framecount == player->idle_frames)
	// 	player->current_img = player->idle_img_1;
	// else if (player->framecount == player->idle_frames * 2)
	// 	player->current_img = player->idle_img_2;
	// else if (player->framecount == player->idle_frames * 3)
	// 	player->current_img = player->idle_img_3;
	// else if (player->framecount == player->idle_frames * 4)
	// 	player->current_img = player->idle_img_4;
	// else if (player->framecount == player->idle_frames * 5)
	// 	player->current_img = player->idle_img_5;
	// else if (player->framecount == player->idle_frames * 6)
	// 	player->current_img = player->idle_img_6;
	// else if (player->framecount == player->idle_frames * 8)
	// {
	// 	player->current_img = player->idle_img_7;
	// 	player->framecount = 0;
	// }
	// player->framecount += 1;
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
	static int frame_corrente=0;
	static double timer_frame = 0.0;
	static double then = 0;
	if(then == 0)
		then = get_time();
	double now = get_time();
	double dt = now - then;
	timer_frame += dt;
	if(timer_frame >= 0.2){
		timer_frame -= 0.2;
		
	}	
	then = now;
	// if (img->basic_framecount == img->basic_idle_frame)
	// 	img->basic_current = img->basic_0;
	// else if (img->basic_framecount == img->basic_idle_frame * 2)
	// 	img->basic_current = img->basic_1;
	// else if (img->basic_framecount == img->basic_idle_frame * 3)
	// {
	// 	img->basic_current = img->basic_2;
	// 	img->basic_framecount = 0;
	// }
	// img->basic_framecount += 1;
}

int	update(t_game *game)
{

	static int frame_corrente=0;
	static double timer_frame = 0.0;
	static double then = 0;
	if(then == 0)
		then = get_time();
	double now = get_time();
	double dt = now - then;
	timer_frame += dt;
	if(timer_frame >= 0.6){
		timer_frame -= 0.6;
		move_enemies(game);
	}	
	then = now;
	if (game->collects > 0)
		door_animation_closed(&game->door_close_img);
	else
		door_animation_opened(&game->door_open_img);
	//player_animation(&game->player);
	enemy_animation(&game->enemy_imgs);
	render(game);
	draw_text(game);
	char *str = ft_itoa(game->collects);
	mlx_string_put(game->mlx, game->window,
		0,
		IMG_SIZE - IMG_SIZE / 1.5,
		-1, str);
	free(str);
	return (1);
}
