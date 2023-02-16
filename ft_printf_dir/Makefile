# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 19:08:54 by aait-mal          #+#    #+#              #
#    Updated: 2022/11/11 16:12:51 by aait-mal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
MANDATORY_SRC = ft_printf.c ft_printf_utils.c ft_putchars.c ft_putnbrs.c \

OBJECT = $(MANDATORY_SRC:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJECT)
	ar rc $(NAME) $(OBJECT)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $<

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all
