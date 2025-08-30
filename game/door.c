/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:27:11 by gmezzini           #+#    #+#            */
/*   Updated: 2022/03/25 16:48:53 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	open_open_door_imgs(t_game *game)
{
	game->door_open_img.idle_img_0 = mlx_xpm_file_to_image(game->mlx,
			"asset/Door/Open/0.xpm", &game->img_size.x, &game->img_size.y);
	game->door_open_img.idle_img_1 = mlx_xpm_file_to_image(game->mlx,
			"asset/Door/Open/1.xpm", &game->img_size.x, &game->img_size.y);
	game->door_open_img.idle_img_2 = mlx_xpm_file_to_image(game->mlx,
			"asset/Door/Open/2.xpm", &game->img_size.x, &game->img_size.y);
	game->door_open_img.idle_img_3 = mlx_xpm_file_to_image(game->mlx,
			"asset/Door/Open/3.xpm", &game->img_size.x, &game->img_size.y);
	game->door_open_img.idle_img_4 = mlx_xpm_file_to_image(game->mlx,
			"asset/Door/Open/4.xpm", &game->img_size.x, &game->img_size.y);
	game->door_open_img.idle_img_5 = mlx_xpm_file_to_image(game->mlx,
			"asset/Door/Open/5.xpm", &game->img_size.x, &game->img_size.y);
	game->door_open_img.idle_img_6 = mlx_xpm_file_to_image(game->mlx,
			"asset/Door/Open/6.xpm", &game->img_size.x, &game->img_size.y);
	game->door_open_img.idle_img_7 = mlx_xpm_file_to_image(game->mlx,
			"asset/Door/Open/7.xpm", &game->img_size.x, &game->img_size.y);
	game->door_open_img.current_img = game->door_open_img.idle_img_0;
}

static void	open_close_door_imgs(t_game *game)
{
	game->door_close_img.idle_img_0 = mlx_xpm_file_to_image(game->mlx,
			"asset/Door/Close/0.xpm", &game->img_size.x, &game->img_size.y);
	game->door_close_img.idle_img_1 = mlx_xpm_file_to_image(game->mlx,
			"asset/Door/Close/1.xpm", &game->img_size.x, &game->img_size.y);
	game->door_close_img.idle_img_2 = mlx_xpm_file_to_image(game->mlx,
			"asset/Door/Close/2.xpm", &game->img_size.x, &game->img_size.y);
	game->door_close_img.idle_img_3 = mlx_xpm_file_to_image(game->mlx,
			"asset/Door/Close/3.xpm", &game->img_size.x, &game->img_size.y);
	game->door_close_img.idle_img_4 = mlx_xpm_file_to_image(game->mlx,
			"asset/Door/Close/4.xpm", &game->img_size.x, &game->img_size.y);
	game->door_close_img.idle_img_5 = mlx_xpm_file_to_image(game->mlx,
			"asset/Door/Close/5.xpm", &game->img_size.x, &game->img_size.y);
	game->door_close_img.idle_img_6 = mlx_xpm_file_to_image(game->mlx,
			"asset/Door/Close/6.xpm", &game->img_size.x, &game->img_size.y);
	game->door_close_img.idle_img_7 = mlx_xpm_file_to_image(game->mlx,
			"asset/Door/Close/7.xpm", &game->img_size.x, &game->img_size.y);
	game->door_close_img.current_img = game->door_close_img.idle_img_0;
}

void	open_door_imgs(t_game *game)
{
	open_open_door_imgs(game);
	open_close_door_imgs(game);
}
