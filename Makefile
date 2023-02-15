# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 18:00:45 by aait-mal          #+#    #+#              #
#    Updated: 2023/02/14 20:55:14 by aait-mal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC =	$(wildcard *.c)
GET_NEXT_LINE_SRC = $(wildcard ./get_next_line_dir/*.c)
OBJ = $(SRC:.c=.o)
HEADER = so_long.h
CC = cc
FLAGS = -Wall -Wextra -Werror
MLFLAGS = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(MLFLAGS) $(OBJ) $(GET_NEXT_LINE_SRC) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -Imlx -c $<

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
