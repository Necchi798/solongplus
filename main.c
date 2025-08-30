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

void test(int key, void *param){
	printf("cippalippa  %d \n", key);
}

void test2(int x,int y, void *param){
	printf("cippalippa  %d  %d \n", x, y);
}

int	main(int argc, char **argv)
{

	t_game	game;
	if (!start(&game, argc, argv))
		return (0);
	mlx_hook(game.window, 6, (1L<<6), test2, &game);
	// mlx_mouse_hook(game.window, test, &game);
	mlx_loop_hook(game.mlx, update, (void *)&game);
	mlx_key_hook(game.window, input, &game);
	mlx_loop(game.mlx);
	return (0);
}
