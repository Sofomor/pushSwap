# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 20:10:32 by imorina           #+#    #+#              #
#    Updated: 2021/11/29 15:32:18 by imorina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** 

NAME	=		libft.a
CCFLAGS =		-Wall -Werror -Wextra

SRCS	=		ft_isalpha.c	ft_isdigit.c	ft_isalnum.c		\
			ft_isascii.c	ft_strlen.c				\
			ft_bzero.c						\
			ft_strlcpy.c	ft_atoi.c				\
			ft_calloc.c	ft_split.c	ft_strdup.c		\
			ft_substr.c	ft_strjoin.c				\
			ft_itoa.c						\
			ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c		\
			ft_putnbr_fd.c


OBJS	=		${SRCS:.c=.o}

all: $(NAME)

$(NAME): ${OBJS}
	ar rcs $@ $^

%.o : %.c
	gcc ${CCFLAGS} -o $@ -c $<

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re
