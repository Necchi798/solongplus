/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:58:29 by gmezzini           #+#    #+#            */
/*   Updated: 2022/03/25 17:04:40 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../map/map.h"

t_tile	**generate_tilemap(char **map, t_game *game);

void	ft_free_chartable(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}

t_tile	**map_init(int argc, char **argv, t_game *game)
{
	char	**map;
	t_tile	**tilemap;

	if (argc == 1 || argc > 2)
	{
		ft_printf("Error\nargomento non passato\n");
		return (NULL);
	}
	map = read_map(argv[1]);
	if (!map)
		return (NULL);
	if (valid_map(map) == FALSE)
	{
		ft_free_chartable(map);
		return (NULL);
	}
	tilemap = generate_tilemap(map, game);
	ft_free_chartable(map);
	if (!tilemap)
		return (NULL);
	return (tilemap);
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->wndw_size.x,
			game->wndw_size.y + 200,
			"so_long");
	open_images(game);
	mlx_hook(game->window, 17, 0, end_program, game);
}

static void	anim_setup(t_game *game)
{
	game->player.framecount = 0;
	game->player.idle_frames = 127;
	game->door_close_img.framecount = 0;
	game->door_close_img.idle_frames = 127;
	game->door_open_img.framecount = 0;
	game->door_open_img.idle_frames = 127;
	game->enemy_imgs.basic_framecount = 0;
	game->enemy_imgs.basic_idle_frame = 127;
}

t_bool	start(t_game *game, int argc, char **argv)
{
	game->status = 0;
	game->collects = 0;
	game->moves = 0;
	game->enemy_list = NULL;
	game->tilemap = map_init(argc, argv, game);
	if (game->tilemap == NULL)
		return (FALSE);
	anim_setup(game);
	game_init(game);
	return (TRUE);
}
