/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:59:50 by gmezzini           #+#    #+#            */
/*   Updated: 2022/03/25 16:45:39 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	open_door_imgs(t_game *game);

static void	open_enemy_imgs(t_game *game)
{

	game->enemy_imgs.frames[0] = mlx_xpm_file_to_image(game->mlx,
			"asset/Enemy/0.xpm", &game->img_size.x, &game->img_size.y);
	game->enemy_imgs.frames[1] = mlx_xpm_file_to_image(game->mlx,
			"asset/Enemy/1.xpm", &game->img_size.x, &game->img_size.y);
	game->enemy_imgs.frames[2] = mlx_xpm_file_to_image(game->mlx,
			"asset/Enemy/1.xpm", &game->img_size.x, &game->img_size.y);
	game->enemy_imgs.basic_current = game->enemy_imgs.frames[0];
}

static void	open_player_imgs(t_game *game)
{

	game->player.front = mlx_xpm_file_to_image(game->mlx,
			"asset/Player/front.xpm", &game->img_size.x, &game->img_size.y);
	game->player.back = mlx_xpm_file_to_image(game->mlx,
			"asset/Player/back.xpm", &game->img_size.x, &game->img_size.y);
	// game->player.left = mlx_xpm_file_to_image(game->mlx,
	// 		"asset/Player/left.xpm", &game->img_size.x, &game->img_size.y);
	// game->player.right = mlx_xpm_file_to_image(game->mlx,
	// 		"asset/Player/right.xpm", &game->img_size.x, &game->img_size.y);
	game->player.current_img = game->player.front;
}
void	open_wall_img(t_game *game)
{
	game->wall_imgs = mlx_xpm_file_to_image(game->mlx, "asset/Wall/wall.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs1 = mlx_xpm_file_to_image(game->mlx, "asset/Wall/wall1.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs2 = mlx_xpm_file_to_image(game->mlx, "asset/Wall/wall2.xpm",
			&game->img_size.x, &game->img_size.y);
}

void	open_images(t_game *game)
{
	int	a;
	int	b;

	a = 457;
	b = 348;
	int menux = 100;
	int menuy = 200;
	game->menuFrame = mlx_xpm_file_to_image(game->mlx, "asset/menu/menuFrame.xpm",
			&menux, &menuy);
	game->chest = mlx_xpm_file_to_image(game->mlx, "asset/chest.xpm",
			&game->img_size.x, &game->img_size.y);
 	game->floor = mlx_xpm_file_to_image(game->mlx, "asset/Wall/floor.xpm",
			&game->img_size.x, &game->img_size.y);
	open_wall_img(game);
	open_player_imgs(game);
	open_door_imgs(game);
	open_enemy_imgs(game);
	game->collects_imgs = mlx_xpm_file_to_image(game->mlx,
			"asset/Collectible/1.xpm", &game->img_size.x, &game->img_size.y);
	game->winmessage = mlx_xpm_file_to_image(game->mlx,
			"asset/Message/Win.xpm", &a, &b);
	game->losemessage = mlx_xpm_file_to_image(game->mlx,
			"asset/Message/Lose.xpm", &a, &b);
}
