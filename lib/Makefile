# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblonde <thblonde@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/15 16:27:11 by thblonde          #+#    #+#              #
#    Updated: 2025/02/15 16:30:24 by thblonde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib.a
SRC = ft_atoi.c \
	ft_isdigit.c \
	ft_split.c \
	ft_strjoin.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_substr.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c
	
OBJ = $(SRC:%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $(OBJ)

obj/%.o: %.c
	@mkdir -p $(dir $@)
	@cc -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -rf obj

fclean: clean
	@rm -rf $(NAME)

re: fclean all