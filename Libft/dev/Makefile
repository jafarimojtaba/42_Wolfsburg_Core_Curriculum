# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/25 00:07:21 by mjafari           #+#    #+#              #
#    Updated: 2021/06/03 00:41:47 by mjafari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC		=	ft_bzero.c ft_isalnum.c ft_isascii.c \
				ft_memccpy.c ft_memcmp.c ft_memmove.c \
				ft_strchr.c ft_strlcat.c ft_strlen.c ft_strnstr.c \
				ft_tolower.c ft_atoi.c ft_calloc.c ft_isalpha.c \
				ft_isdigit.c ft_isprint.c ft_memchr.c \
				ft_memcpy.c ft_memset.c ft_strdup.c ft_strlcpy.c \
				ft_strncmp.c ft_strrchr.c ft_toupper.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
				ft_strmapi.c

BNC		=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c

SRC_OBJ	=	$(SRC:.c=.o)

BNC_OBJ	=	$(BNC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC)
	ar rc $(NAME) $(SRC_OBJ)
	ranlib $(NAME)

bonus:
	gcc -c -Wall -Wextra -Werror $(BNC) $(SRC)
	ar rc $(NAME) $(BNC_OBJ) $(SRC_OBJ)
	ranlib $(NAME)

clean:
	rm -f $(SRC_OBJ) $(BNC_OBJ)

fclean: clean
	rm -f $(NAME) $(NAME:.a=.so)

re: fclean all

so:
	gcc -nostartfiles -c -Wall -Wextra -Werror $(SRC) $(BNC)
	gcc -nostartfiles -shared -o libft.so $(SRC_OBJ) $(BNC_OBJ) 

test: $(NAME) bonus
	gcc -lbsd ../test/main_test.c -L. -lft
	./a.out
	@rm -f ./a.out
