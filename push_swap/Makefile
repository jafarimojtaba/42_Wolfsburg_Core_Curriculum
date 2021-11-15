# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 15:53:06 by mjafari           #+#    #+#              #
#    Updated: 2021/11/15 11:34:04 by mjafari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRC		=	push_swap.c ./Src/*.c

FLAG	=	-Wall -Werror -Wextra

SRC_OBJ	=	$(SRC:.c=.o)

LIBPATH	=	./Libft

LIBRARY	=	libft.a

all: $(LIBRARY) $(NAME)

$(LIBRARY):
	make bonus -C $(LIBPATH)

$(NAME): $(SRC)
	$(CC) $(FLAG) -g -o $(NAME) $(SRC) -L $(LIBPATH) -lft

clean:
	rm -f $(SRC_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(SRC)
	$(CC) -g -o $(NAME) $(SRC) -L $(LIBPATH) -lft