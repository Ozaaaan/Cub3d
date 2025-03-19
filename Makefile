# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 13:28:06 by ozdemir           #+#    #+#              #
#    Updated: 2025/03/19 14:03:17 by ozdemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iinc -g

NAME = cub3D

SRC_DIR = src
INC_DIR = inc

SRC = 	main.c \
	parsing/utils.c \
	parsing/utils2.c \
	parsing/parsing.c \
	parsing/parsing2.c \
	parsing/parsing3.c \
	parsing/parsing4.c \
	parsing/verif.c \
	parsing/map.c \
	parsing/map2.c \
	executing/player.c \
	executing/draw.c \
	executing/raycasting.c \
	executing/movement.c \
	executing/movement2.c \
	executing/textures.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = inc/Libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX = inc/libmlx42.a
LIBS = $(MLX) -ldl -lglfw -pthread -L$(LIBFT_DIR) -lft -lm

RM = rm -f

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
