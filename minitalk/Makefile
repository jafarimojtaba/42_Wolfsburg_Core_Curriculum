# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 22:06:49 by mjafari           #+#    #+#              #
#    Updated: 2021/12/20 22:26:07 by mjafari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS		=	-Wall -Werror -Wextra

LIB_PATH	=	./libft
LIB			=	libft.a

NAME		=	client
NAME_1		=	server

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

all: $(LIB) $(NAME) $(NAME_1)

$(LIB):
	make -C $(LIB_PATH)

$(NAME): $(CLIENT_SRCS)
	clang $(CFLAGS) $(CLIENT_SRCS) -L $(LIB_PATH) -lft -o $(NAME)

$(NAME_1): $(SERVER_SRCS)
	clang $(CFLAGS) $(SERVER_SRCS) -L $(LIB_PATH) -lft -o $(NAME_1)

clean:
	make clean -C $(LIB_PATH)
	rm -f $(CLIENT_SRCS) $(SERVER_SRCS)

fclean: clean
	make fclean -C $(LIBPATH)
	rm -f $(NAME) $(NAME_1)

re: fclean all