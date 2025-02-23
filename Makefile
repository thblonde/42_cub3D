# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblonde <thblonde@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 14:05:55 by matcoppo          #+#    #+#              #
#    Updated: 2025/02/15 16:36:17 by thblonde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
MLX = lib/mlx/libmlx.a -Lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz

SRC = src/1.main.c \
		src/0.ft_free.c \
		src/0.utils_parsing.c \
		src/2.open_file.c \
		src/3.parse_identifier.c \
		src/4.map_in_file.c \
		src/5.parse_map.c \
		src/init.c \
		src/draw.c \
		src/player_moves.c 

OBJ = $(SRC:src/%.c=obj/%.o)

all: logo $(NAME)

$(NAME): $(OBJ)
	@make -C lib/
	@make -C lib/mlx/
#@cc -Wall -Wextra -Werror $(OBJ) -o $@ lib/lib.a $(MLX)
	@cc -Wall -Wextra -Werror $(OBJ) -o $@ lib/lib.a $(MLX)
	@echo "\033[0;32m Compiling Success!\033[0m"

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@ -g

logo :
	@echo "\033[0;34m"
	@echo " ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░▒▓███████▓▒░░▒▓███████▓▒░  "
	@echo "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░     ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ "
	@echo "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░     ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ "
	@echo "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░ "
	@echo "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░     ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ "
	@echo "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░     ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ "
	@echo " ░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓███████▓▒░▒▓███████▓▒░░▒▓███████▓▒░  "
	@echo "\033[0m"

clean:
	@make clean -C lib/
	@rm -rf obj

fclean: clean
	@make fclean -C lib/
#@make clean -C lib/mlx/
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
