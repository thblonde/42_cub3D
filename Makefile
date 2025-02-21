NAME = cub3d

SOURCES = src/main.c
OBJECTS = $(SOURCES:src/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	   make -C mlx/
	   cc $(OBJECTS) -o $@ mlx/libmlx_Linux.a -lXext -lX11 -lm
		  rm -rf obj
obj/%.o: src/%.c
	   mkdir -p $(dir $@)
	   cc -c -I./include $< -o $@
clean:
	make clean -C mlx/
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all
