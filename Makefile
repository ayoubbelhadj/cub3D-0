# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 14:44:25 by aoudija           #+#    #+#              #
#    Updated: 2023/06/02 14:50:23 by aoudija          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube3D

CC = cc

CFLAGS = -Wall -Wextra -Werror

mlx_FLAGS = -lmlx -framework OpenGL -framework AppKit

DEPS = cube.h

FILES = 

OBG = $(FILES:.c=.o)

OBGB = $(FILES_B:.c=.o)

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBG)
	$(CC) $(CFLAGS) $(OBG) $(mlx_FLAGS) -o $(NAME)

clean:
	rm -f $(OBG)

fclean: clean
	rm -f $(NAME)

re:fclean all

.PHONY:all clean fclean re