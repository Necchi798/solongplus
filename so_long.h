/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:00:10 by gmezzini           #+#    #+#            */
/*   Updated: 2022/03/25 16:45:53 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "basics.h"
#include <stdio.h>
# include "./minilibx/mlx.h"

# define IMG_SIZE 64
# define CAMERA_SIZE 6
# define MAP_HEIGHT 30
# define MAP_WIDTH 30
typedef enum e_direction{
	
	UP = 1,
	RIGHT = 2,
	DOWN = 3,
	LEFT = 4,

} t_direction;

typedef enum e_tiletype
{
	IND_WALL = 'I',
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'M',
	POWER_UP = 'U',

}	t_tiletype;

enum {
	ON_KEYDOWN = 2,
	ON_RIGHT = 68,
};

typedef struct s_tile
{
	t_tiletype		type;
	t_vector		position;
	int 	visited;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef struct s_player
{

	t_direction direction;
	double then;
	t_tile	*tile;
	void	*current_img;
	int		framecount;
	int		idle_frames;
	void	*frames[8];
	void	*idle_img_0;
	void	*idle_img_1;
	void	*idle_img_2;
	void	*idle_img_3;
	void	*idle_img_4;
	void	*idle_img_5;
	void	*idle_img_6;
	void	*idle_img_7;

}	t_player;

typedef struct s_door
{
	t_tile	*tile;
	void	*current_img;
	int		framecount;
	int		idle_frames;
	void	*idle_img_0;
	void	*idle_img_1;
	void	*idle_img_2;
	void	*idle_img_3;
	void	*idle_img_4;
	void	*idle_img_5;
	void	*idle_img_6;
	void	*idle_img_7;
}	t_door;

typedef enum e_enemytype
{
	HORIZONTAL_ENEM = 'H',
	VERTICAL_ENEM = 'V',
}	t_enemyytpe;

typedef struct s_enemy
{
	t_enemyytpe			type;
	int					dir;
	t_tile				*tile;
	struct s_enemy		*next;
}	t_enemy;

typedef struct s_enemy_imgs
{
	int		basic_framecount;
	int		basic_idle_frame;
	void	*basic_current;
	void	*basic_0;
	void	*basic_1;
	void	*basic_2;

}	t_enemy_img;

typedef struct s_game
{
	void			*chest;
	void			*menuFrame;
	void			*floor;
	void			*mlx;
	void			*window;
	t_vector		wndw_size;
	t_tile			**tilemap;
	t_player		player;
	int				collects;
	int				moves;
	t_enemy			*enemy_list;
	t_vector		img_size;
	void			*wall_imgs;
	void			*collects_imgs;
	t_enemy_img		enemy_imgs;
	t_door			door_open_img;
	t_door			door_close_img;
	void			*winmessage;
	void			*losemessage;
	int				status;
	void			*wall_imgs1;
	void			*wall_imgs2;
}	t_game;

t_bool	start(t_game *game, int argc, char **argv);
int		end_program(t_game *game);
int		update(t_game *game);
void	render(t_game *game);
void	open_images(t_game *game);
int		input(int key, t_game *game);
t_tile	**map_init( t_game *game);

#endif