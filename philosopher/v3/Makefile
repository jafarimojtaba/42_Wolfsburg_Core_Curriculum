# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 18:20:50 by mjafari           #+#    #+#              #
#    Updated: 2022/06/13 15:20:17 by mjafari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
INCLUDES = philo.h
SRC = ft_atoi.c main.c init.c utils.c actions.c

OBJ = $(SRC:.c=.o)

all: fclean $(NAME)

$(NAME):
	$(CC) -pthread -Wall -Werror -Wextra $(SRC) -o $(NAME)

clean: 
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all
