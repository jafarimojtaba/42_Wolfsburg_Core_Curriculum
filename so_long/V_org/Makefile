# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 12:09:32 by mjafari           #+#    #+#              #
#    Updated: 2022/02/03 15:52:26 by mjafari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRC		=	main.c ./gnl/*.c

FLAG	=	-Wall -Werror -Wextra

SRC_OBJ	=	$(SRC:.c=.o)

LIBPATH	=	./libft

LIBRARY	=	libft.a

all: $(LIBRARY) $(NAME)

$(LIBRARY):
	make -C $(LIBPATH)

$(NAME): $(SRC)
	$(CC) $(FLAG) -g -o $(NAME) $(SRC) -L $(LIBPATH) -lft -L mlx -lmlx -framework OpenGL -framework AppKit

clean:
	make clean -C $(LIBPATH)
	rm -f $(SRC_OBJ)

fclean: clean
	make fclean -C $(LIBPATH)
	rm -f $(NAME)
	rm -f checker

re: fclean all