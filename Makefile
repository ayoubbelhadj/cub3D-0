# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 14:44:25 by aoudija           #+#    #+#              #
#    Updated: 2023/06/02 14:45:22 by aoudija          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube3D

CC = cc

CFLAGS = -Wall -Wextra -Werror

mlx_FLAGS = -lmlx -framework OpenGL -framework AppKit

DEPS = so_long.h

FILES = 

FILES_B = bonus/so_long_bonus.c  mandatory/get_next_line.c mandatory/fill.c mandatory/ft_utils.c mandatory/img_ptr.c \
		move_bonus/playerb_down.c move_bonus/playerb_up.c move_bonus/playerb_right.c move_bonus/playerb_left.c \
		bonus/key_press_bonus.c mandatory/pickle_exist.c mandatory/ft_putnbr_fd.c  mandatory/on_close.c \
		parsing_bonus/check_bitems.c parsing/is_rectangular.c parsing/check_walls.c bonus/morty_img.c \
		bonus/animation.c bonus/morty_exist.c bonus/frame.c ft_itoa.c is_playable/is_playable.c  filler.c is_playable/player_pos.c ft_split.c ft_strtrim.c \

OBG = $(FILES:.c=.o)

OBGB = $(FILES_B:.c=.o)

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBG)
	$(CC) $(CFLAGS) $(OBG) $(mlx_FLAGS) -o $(NAME) 

bonus : $(B_NAME)

$(B_NAME) : $(OBGB)
	$(CC) $(CFLAGS) $(OBGB) $(mlx_FLAGS) -o $(B_NAME)

clean:
	rm -f $(OBG) $(OBGB)

fclean: clean
	rm -f $(NAME) $(B_NAME)

re:fclean all

.PHONY:all clean fclean re bonus