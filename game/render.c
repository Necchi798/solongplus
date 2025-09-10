/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:21:00 by gmezzini           #+#    #+#            */
/*   Updated: 2022/03/25 16:28:49 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_text(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->window,
		game->wndw_size.x - IMG_SIZE / 2.3,
		IMG_SIZE - IMG_SIZE / 1.5,
		-1, str);
	free(str);
}

void	draw_wall(t_tile tile, t_game game, t_vector pos)
{
	if (tile.up == NULL)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs1, pos.x, pos.y);
	else if (tile.down == NULL)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs2, pos.x, pos.y);
	else
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs, pos.x, pos.y);
}

static void	draw_image(t_tile tile, t_game game, t_vector pos)
{
	mlx_put_image_to_window(game.mlx, game.window,
		game.floor, pos.x, pos.y);
	if (tile.type == WALL || tile.type == IND_WALL)
		draw_wall(tile, game, pos);
	else if (tile.type == EXIT)
	{
		if (game.collects > 0)
			mlx_put_image_to_window(game.mlx, game.window,
				game.door_close_img.current_img, pos.x, pos.y);
		else
			mlx_put_image_to_window(game.mlx, game.window,
				game.door_open_img.current_img, pos.x, pos.y);
	}
	else if (tile.type == COLLECTABLE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.collects_imgs, pos.x, pos.y);
	else if (tile.type == ENEMY)
		mlx_put_image_to_window(game.mlx, game.window,
			game.enemy_imgs.basic_current, pos.x, pos.y);
	else if (tile.type == PLAYER && game.player.tile != NULL)
		mlx_put_image_to_window(game.mlx, game.window,
			game.player.current_img, pos.x, pos.y);
	else if (tile.type == POWER_UP)
		mlx_put_image_to_window(game.mlx, game.window,
			game.chest, pos.x, pos.y);

}
void renderMenu (t_game game){
	int mStartX=(game.wndw_size.x / 2) - 350;
	mlx_put_image_to_window(game.mlx,game.window,game.menuFrame,mStartX,game.wndw_size.y );
	mlx_put_image_to_window(game.mlx,game.window,game.chest,mStartX + 4,game.wndw_size.y +4 );

}

void renderMinimap(t_game game){
	int scale = 5;
	int tile_color;
	// void *minimap = mlx_new_image(game.mlx,180,180 );
	for (int map_y = 0; map_y < MAP_HEIGHT; ++map_y) {
		for (int map_x = 0; map_x < MAP_WIDTH; ++map_x) {
			  switch (game.tilemap[map_y][map_x].type) {
				case IND_WALL: 		tile_color = 0x000000FF;   break;
                case WALL:          tile_color = 0xFF654321;   break;
                case PLAYER:        tile_color = 0x0000FF00;   break;
				case COLLECTABLE:	tile_color = 0xFFFFFF00;   break;
				//case EMPTY:			tile_color = 0xFF8B4513;   break;
				case EXIT:			tile_color = 0xFF00FF00;   break;
                default:            tile_color = 0xFF8B4513;  break;
            }
			int start_screen_x = 600 + (map_x * 6);
            int start_screen_y = 508 + (map_y * 6);
			if(game.tilemap[map_y][map_x].visited){
			for (int py = 0; py < scale; ++py) {
				for (int px = 0; px < scale; ++px) {
					mlx_pixel_put(game.mlx,game.window, start_screen_x  + px, start_screen_y  + py, tile_color);
				}
			}}
		}
	}
}


void	render(t_game *game)
{
	t_tile	tile;
	int		x;
	int		y;

	mlx_clear_window(game->mlx, game->window);
	int cameraSize = 6;
	int camerax = game->player.tile->position.x/64 - cameraSize / 2;
	int cameray = game->player.tile->position.y/64 - cameraSize / 2;
	int maxCameraX = (( MAP_HEIGHT) - cameraSize);
	int maxCameray = (( MAP_WIDTH ) - cameraSize);
	int viewPortX = game->wndw_size.x / 2 - (64 * cameraSize/2);
	if(camerax < 0)
		camerax = 0;
	else if(camerax > maxCameraX)
		camerax= maxCameraX;
	if(cameray < 0)
		cameray = 0;
	else if(cameray > maxCameray)
		cameray = maxCameray;
	y = cameray;
	
	while (game->tilemap[y] != NULL && y <= cameray + cameraSize -1 )
	{
		x = camerax;
		while (game->tilemap[y][x].type != 0 && x <= camerax + cameraSize -1)
		{
			tile = game->tilemap[y][x];
			game->tilemap[y][x].visited = 1;
			tile.position.x = tile.position.x  = (x - camerax) * 64 + viewPortX;
			tile.position.y = tile.position.y = (y - cameray) * 64 + 50;

			draw_image(tile, *game, tile.position);
			x++;
		}
		y++;
	}
	
	//renderMenu(game);
	renderMinimap(*game);
	if (game->status == 1){
		printf("%d %d", game->status, game->collects);
		game->status = 0;
		game->tilemap = map_init(game);
	}
	if (game->status == -1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->losemessage, game->wndw_size.x / 2 - 228,
			game->wndw_size.y - 348);
}
