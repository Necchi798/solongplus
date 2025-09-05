# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 13:54:12 by gmezzini           #+#    #+#             #
#    Updated: 2022/03/24 16:43:34 by gmezzini          ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

CC = gcc
INCLUDE = -framework OpenGL -framework AppKit -lmlx

NAME = so_long
SRC = $(SRC_GNL) $(SRC_MAP) $(SRC_GAME) main.c

GNL = get_next_line.c get_next_line_utils.c
SRC_GNL = $(addprefix gnl/, $(GNL))

FT_PRINTF_A = libftprintf.a
FT_PRINTF_DIR = ft_printf/
FT_PRINTF = $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_A))

LIBFT_A = libft.a
LIBFT_DIR = libft/
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_A))

MLX_A = libmlx_Linux.a
MLXDIR = minilibx-linux/
MLX = $(addprefix $(MLXDIR), $(MLX_A))
MAP = read_map.c check_map.c map_check_utils.c tilemap.c enemy_gen.c
SRC_MAP = $(addprefix map/, $(MAP))

GAME = game_int.c end_program.c image.c update.c render.c door.c input.c enemy.c 
SRC_GAME = $(addprefix game/, $(GAME))

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC)  -c $< -o $@

$(NAME) : $(OBJ)
	make -C $(LIBFT_DIR)
	make -C $(FT_PRINTF_DIR)
	$(CC)   $(OBJ) $(FT_PRINTF) $(LIBFT)  -Lmlx_Linux -lmlx_Linux -L ./minilibx -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz -lrt -g -o $(NAME)

all: $(NAME)

play: all
	./$(NAME) map.ber

bonus: all

clean:
	rm -rf $(OBJ) $(B_OBJ)
	make clean -C $(FT_PRINTF_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(FT_PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus play