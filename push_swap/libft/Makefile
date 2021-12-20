# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/22 19:29:10 by mjafari           #+#    #+#              #
#    Updated: 2021/11/28 00:25:39 by mjafari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDES = libft.h
FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_striteri.c\
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJ = $(FILES:.c=.o)

OBJBONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(BONUS) $(FILES)
	ar rc $(NAME) $(OBJBONUS) $(OBJ)
	ranlib $(NAME)

bonus:
	gcc -Wall -Werror -Wextra -c $(BONUS) $(FILES)
	ar rc $(NAME) $(OBJBONUS) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	gcc -nostartfiles -c -Wall -Wextra -Werror $(FILES)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

.PHONY: all clean fclean re
