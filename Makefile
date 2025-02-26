# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 13:28:06 by ozdemir           #+#    #+#              #
#    Updated: 2025/02/26 16:34:25 by ozdemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iinc -g

NAME = cub3D

SRC_DIR = src
INC_DIR = inc

SRC = 	main.c \
	utils.c \
	

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = inc/Libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX = inc/libmlx42.a
LIBS = $(MLX) -ldl -lglfw -pthread -L$(LIBFT_DIR) -lft

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
