# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 15:53:06 by mjafari           #+#    #+#              #
#    Updated: 2021/11/28 00:41:23 by mjafari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRC		=	main.c ./handel/*.c ./operations/*.c ./my_checker/*.c

FLAG	=	-Wall -Werror -Wextra

SRC_OBJ	=	$(SRC:.c=.o)

LIBPATH	=	./libft

LIBRARY	=	libft.a

all: $(LIBRARY) $(NAME)

$(LIBRARY):
	make -C $(LIBPATH)

$(NAME): $(SRC)
	$(CC) $(FLAG) -g -o $(NAME) $(SRC) -L $(LIBPATH) -lft

clean:
	make clean -C $(LIBPATH)
	rm -f $(SRC_OBJ)

fclean: clean
	make fclean -C $(LIBPATH)
	rm -f $(NAME)
	rm -f checker

re: fclean all

checker: all
	$(CC) $(FLAG) -g -o checker $(SRC) -L $(LIBPATH) -lft