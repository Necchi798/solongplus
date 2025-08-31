#define STB_PERLIN_IMPLEMENTATION
#include "stb_perlin.h"
#include <stdlib.h>
#include <time.h>


// Le dimensioni della tua mappa
#define MAP_WIDTH 30
#define MAP_HEIGHT 30

// Definiamo i nostri tipi di tile per chiarezza
typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'M',
	POWER_UP = 'U',
}	t_tiletype;

// Il nostro array 2D che conterrà la mappa generata
char map[MAP_WIDTH][MAP_HEIGHT];

void main() {
    // --- Parametri per controllare la generazione ---

    // La "frequenza" o "scala" del rumore.
    // Valori più bassi -> zoom out, continenti più grandi.
    // Valori più alti -> zoom in, terreno più frastagliato.
    float frequency = 5.0f;

    // Un "seme" per la generazione. Cambiandolo, ottieni una mappa diversa.
    srand(time(NULL));
    float seed = (float)rand();

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
            float wall_threshold = 0.15f; 
            // Mappiamo il valore di rumore a un tipo di tile
            if (noise_value > wall_threshold )  {
                map[x][y] = WALL;
            } else {
                map[x][y] = EMPTY;
            }
            if(x == 0 || x == MAP_WIDTH -1)
                map[x][y] = WALL;
            if(y == 0 || y == MAP_HEIGHT -1)
                map[x][y] = WALL;
        }
    }
    printf("Mappa generata!\n");

    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
             switch (map[x][y]) {
                case EMPTY:
                    printf("0"); // Spazio vuoto per il suolo
                    break;
                case WALL:
                    printf("1"); // Cancelletto per i muri
                    break;
                case COLLECTABLE:
                    printf("C"); // 'C' per le monete
                    break;
                default:
                    printf("?"); // Un punto interrogativo se qualcosa non va
                    break;
            }
        }
        printf("\n");

    }   
    
}