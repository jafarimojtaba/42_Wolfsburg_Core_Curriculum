# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 22:28:27 by mjafari           #+#    #+#              #
#    Updated: 2022/02/23 22:55:00 by mjafari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
SRCS	= main.c ./gnl/*.c
HEADER	= so_long.h
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
LIBFT	= libft
FLGFT	= -Llibft -lft
APLFLG	= -L /usr/X11/lib -lXext -lX11 -lm
WINFLG	= -Lminilibx -lmlx -lXext -lX11 -lm
MLX		= minilibx

$(NAME): $(SRCS) $(MLX) $(LIBFT)
	make bonus -C $(LIBFT)
	make -C $(MLX)
	$(CC) $(SRCS) $(FLAGS) $(WINFLG) $(FLGFT) -o $(NAME)

apple: $(SRCS) $(MLX) $(LIBFT)
	make bonus -C $(LIBFT)
	make -C $(MLX)
	$(CC) $(SRCS) $(FLAGS) $(FLGFT) $(APLFLG) ./minilibx/libmlx.a -o $(NAME)

all: $(NAME)

clean: $(LIBFT) $(MLX)
	make clean -C $(LIBFT)
	make clean -C $(MLX)

fclean: $(LIBFT) $(MLX)
	rm -f $(NAME)
	rm -f $(MLX)/libmlx.a
	rm -f $(MLX)/libmlx_$(shell uname).a
	make fclean -C $(LIBFT)
	make clean -C $(MLX)

re: fclean all