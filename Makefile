# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 17:38:15 by lquehec           #+#    #+#              #
#    Updated: 2023/12/01 19:55:21 by lquehec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS := $(shell uname)
SRCS_DIR	= ./src/
HEADER_DIR	= ./includes/
MLX_DIR =  ./mlx/
ifeq ($(OS), Darwin)
    MLX_DIR = ./mlx_opengl/
else
    MLX_DIR = ./mlx/
endif
LIBFT_DIR	= ./libft/

SRCS 		= $(addprefix $(SRCS_DIR),\
				main.c \
				init.c \
				exit.c \
				error.c \
				free.c \
				map_get.c \
				map_check.c \
				render.c \
				gameplay.c \
				map_utils.c \
				mlx.c \
				utils.c )

OBJS		= $(SRCS:.c=.o)

CC			= cc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -Imlx

# LIBRARY
MAKE_MLX	= make -C $(MLX_DIR)
MLX_A		= $(MLX_DIR)libmlx.a
ifeq ($(OS), Darwin)
	MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
	MLX_FLAGS	= -L$(MLX_DIR) -I -g3 -L /usr/X11/lib -L$(HEADER_DIR) -L$(MLX_DIR) -lmlx -I$(MLX_DIR) -lXext -lX11 -lz -lm
endif
# LIBFT
MAKE_LIBFT	= make -s -C $(LIBFT_DIR)
LIBFT_A		= $(LIBFT_DIR)libft.a

NAME		= so_long

.c.o:
			$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(MAKE_LIBFT) all bonus
			$(MAKE_MLX)
			$(CC) $(CFLAGS) -I $(HEADER_DIR) -I $(MLX_DIR) $(OBJS) $(LIBFT_A) $(MLX_A) $(MLX_FLAGS)  -o $(NAME)

all: 		$(NAME)

clean:
			$(RM) $(OBJS)
			$(MAKE_LIBFT) clean
			# $(MAKE_MLX) clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE_LIBFT) fclean
			# $(MAKE_MLX) clean

re:			fclean all

.PHONY: all clean fclean re