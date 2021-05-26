# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/25 00:07:21 by mjafari           #+#    #+#              #
#    Updated: 2021/05/26 11:01:07 by mjafari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC		=	ft_bzero.c ft_isalnum.c ft_isascii.c ft_islower.c \
				ft_isspace.c ft_memccpy.c ft_memcmp.c ft_memmove.c \
				ft_strchr.c ft_strlcat.c ft_strlen.c ft_strnstr.c \
				ft_tolower.c libft.h ft_atoi.c ft_calloc.c ft_isalpha.c \
				ft_isdigit.c ft_isprint.c ft_isupper.c ft_memchr.c \
				ft_memcpy.c ft_memset.c ft_strdup.c ft_strlcpy.c \
				ft_strncmp.c ft_strrchr.c ft_toupper.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c

all: $(NAME)

$(NAME): clean
	gcc -c -Wall -Wextra -Werror $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)
	rm -f *.o *.gch

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	
re: fclean all

test: $(NAME)
	gcc -Wall -Werror -Wextra -lbsd ../test/main_test.c -L. -lft
	./a.out
	@rm -f ./a.out
