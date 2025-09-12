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
#define STB_PERLIN_IMPLEMENTATION
#include "../so_long.h"
#include "../map/map.h"
#include "stb_perlin.h"
#include <time.h>



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

int  find_random_empty_tile(int* out_x, int* out_y,char **map) {
    // Tentiamo un numero massimo di volte per evitare loop infiniti
    // se la mappa fosse quasi piena.
    for (int i = 0; i < 1000; i++) {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;
        if (map[x][y] == '0') {
            *out_x = x;
            *out_y = y;
            return 1;
        }
    }
    return 0; // Non siamo riusciti a trovare uno spazio vuoto
}


void place_game_elements(int num_coins,int num_e,char **map) {
    int x, y;

    // 1. Posiziona il Giocatore ('P')
    if (find_random_empty_tile(&x, &y,map)) {
        map[x][y] = 'P';
    } else {
        printf("ERRORE: Non c'è spazio per posizionare il giocatore!\n");
        return;
    }

    if (find_random_empty_tile(&x, &y,map)) {
        map[x][y] ='E';
    } else {
        printf("ERRORE: Non c'è spazio per posizionare l'uscita!\n");
        return;
    }

    for (int i = 0; i < num_coins; i++) {
        if (find_random_empty_tile(&x, &y,map)) {
            map[x][y] = 'C';
        } else {
            printf("ATTENZIONE: Spazio esaurito, posizionate solo %d monete.\n", i);
            break;
        }
    }
    for (int i = 0; i < num_e; i++) {
        if (find_random_empty_tile(&x, &y,map)) {
            map[x][y] = 'V';
        } else {
            break;
        }
    }
}

char** genMap() {
    // --- Parametri per controllare la generazione ---

    // La "frequenza" o "scala" del rumore.
    // Valori più bassi -> zoom out, continenti più grandi.
    // Valori più alti -> zoom in, terreno più frastagliato.
    float frequency = 5.0f;

    // Un "seme" per la generazione. Cambiandolo, ottieni una mappa diversa.
    srand(time(NULL));
    float seed = (float)rand();
    char **map = malloc(MAP_HEIGHT * sizeof(char*));
    for (int i = 0; i < MAP_HEIGHT; i++) {
        map[i] =malloc(MAP_WIDTH * sizeof(char));
    }
    // char map[MAP_WIDTH][MAP_HEIGHT];

    printf("Generazione mappa...\n");

    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            // Normalizziamo le coordinate per non dipendere dalle dimensioni della mappa
            // e le moltiplichiamo per la frequenza.
            float nx = (float)x / MAP_WIDTH * frequency;
            float ny = (float)y / MAP_HEIGHT * frequency;

            // Calcoliamo il valore di rumore per questo punto.
            // Usiamo la versione 3D per poter includere un seme.
            // Il risultato è un valore tra -1.0 e 1.0.
            float noise_value = stb_perlin_noise3(nx, ny, seed, 0, 0, 0);
            float wall_threshold = 0.05f; 
            // Mappiamo il valore di rumore a un tipo di tile
            if (noise_value > wall_threshold )  {
                map[x][y] = WALL;
            } else {
                map[x][y] = EMPTY;
            }
            if(x == 0 || x == MAP_WIDTH -1)
                map[x][y] = IND_WALL;
            if(y == 0 || y == MAP_HEIGHT -1)
                map[x][y] = IND_WALL;
        }
    }
	place_game_elements(COLLECTS_NMB,ENEMY_NMB,map);
    printf("Mappa generata!\n");
     for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x){
            printf("%c",map[y][x]);
        }
        printf("\n");
     }
    return map;
}

t_tile	**map_init( t_game *game)
{
	char	**map;
	t_tile	**tilemap;


	map = genMap();
	if (!map)
		return (NULL);
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
    game->points = 0;
	game->moves = 0;
	game->enemy_list = NULL;
	game->tilemap = map_init( game);
	if (game->tilemap == NULL)
		return (FALSE);
	anim_setup(game);
	game_init(game);
	return (TRUE);
}
