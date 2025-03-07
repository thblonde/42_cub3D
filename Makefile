NAME = cub3D
SRC = srcs/main.c srcs/draw.c srcs/player.c
OBJ = $(SRC:srcs/%.c=obj/%.o)
INCLUDES = -I./includes
OS = $(shell uname)

ifeq ($(OS), Linux)
	MLX = lib/mlx/libmlx.a -Lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
else
	MLX = -Lmlx -lmlx -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/
	make -C mlx/
	cc -Wall -Wextra -Werror  $(OBJ) -o $@ lib/lib.a mlx/libmlx.a $(MLX)

obj/%.o: srcs/%.c
	mkdir -p $(dir $@)
	$(CC) $(INCLUDES) -c $< -o $@ -g

clean:
	make clean -C lib/
	rm -rf obj

fclean: clean
	make fclean -C lib/
	make clean -C mlx/
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
