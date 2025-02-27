NAME = cub3D
MLX = lib/mlx/libmlx.a -Lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
INCLUDES = -I./includes
SRC = srcs/main.c srcs/draw.c srcs/player.c srcs/raycast.c
OBJ = $(SRC:src/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/
	make -C lib/mlx/
	cc -Wall -Wextra -Werror $(INCLUDES) $(OBJ) -o $@ lib/lib.a $(MLX)

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@ -g

clean:
	make clean -C lib/
	rm -rf obj

fclean: clean
	make fclean -C lib/
	make clean -C lib/mlx/
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
