/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:48:32 by gmezzini           #+#    #+#            */
/*   Updated: 2022/03/22 16:15:16 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "basics.h"
#include "map/map.h"
#include "so_long.h"

//TODO ci devessere un modo migliore di questa porcata

int click = 0;
void test(int key, void *param){
	printf("cippalippa  %d \n", key);
	click = 1;
}

int test2(int x,int y, t_game *game){
	int offsetX =  (( game->wndw_size.x) - (CAMERA_SIZE * 64)) /2;
	printf("cippalwwippa  %d  %d \n", x  , y );
	if(click == 1){
		click = 0;
		printf("%d %d",(x - offsetX ) /64, y /64);
		// game->tilemap[y /64][(x - offsetX ) /64].type = WALL;
	}
	return 0;
}

int	main(int argc, char **argv)
{
	t_game	game;
	if (!start(&game, argc, argv))
		return (0);
	mlx_hook(game.window, 6, (1L<<6), test2,  (void *)&game);
	mlx_mouse_hook(game.window, test, (void *)&game);
	mlx_loop_hook(game.mlx, update, (void *)&game);
	mlx_key_hook(game.window, input, &game);
	mlx_loop(game.mlx);
	return (0);
}
