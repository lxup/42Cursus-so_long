# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lquehec <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 17:38:15 by lquehec           #+#    #+#              #
#    Updated: 2023/12/04 11:42:36 by lquehec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
END=$'\x1b[0m
BOLD=$'\x1b[1m
UNDER=$'\x1b[4m
REV=$'\x1b[7m
GREY=$'\x1b[30m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
YELLOW=$'\x1b[33m
BLUE=$'\x1b[34m
PURPLE=$'\x1b[35m
CYAN=$'\x1b[36m
WHITE=$'\x1b[37m

OS 			:= $(shell uname)
SRCS_DIR	= ./src/
HEADER_DIR	= ./includes/

SRCS 		= $(addprefix $(SRCS_DIR),\
				main.c \
				init.c \
				exit.c \
				error.c \
				free.c \
				map_get.c \
				map_check.c \
				render.c \
				render_floor.c \
				render_interface.c \
				gameplay.c \
				map_utils.c \
				mlx.c \
				utils.c )

OBJS		= $(SRCS:.c=.o)

CC			= cc
RM			= rm -f
MF 			= Makefile

ifeq ($(OS), Darwin)
    CFLAGS	= -Wall -Wextra -Werror -Imlx
else
    CFLAGS	= -Wall -Wextra -Werror
endif

# LIBRARY
ifeq ($(OS), Darwin)
	MLX_DIR 	= ./mlx-opengl
	MLX_FLAGS	= -framework OpenGL -framework Appkit -l z
	MLX_PATH 	= $(MLX_DIR)/libmlx.a
	# MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR 	= ./mlx-linux
	MLX_FLAGS	= -lXext -lX11 -lm -lbsd
	MLX_PATH	= $(MLX_DIR)/libmlx.a
	# MLX_FLAGS	= -L$(MLX_DIR) -I -g3 -L /usr/X11/lib -L$(HEADER_DIR) -L$(MLX_DIR) -lmlx -I$(MLX_DIR) -lXext -lX11 -lz -lm
endif
MAKE_MLX	= make -C $(MLX_DIR)

# LIBFT
LIBFT_DIR	= ./libft
MAKE_LIBFT	= make -s -C $(LIBFT_DIR)
LIBFT_PATH	= $(LIBFT_DIR)/libft.a

NAME		= so_long

.c.o:
			@/bin/echo -n .
			@$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $(<:.c=.o)

$(NAME):	$(MF) $(OBJS) libft mlx
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH) $(MLX_PATH) $(MLX_FLAGS)  -o $(NAME)
			@echo "\n${GREEN}> so_long was successfuly compiled 🎉${END}"

all: 		$(NAME)

clean:
			@$(RM) $(OBJS)
			@$(MAKE_LIBFT) clean
			@$(MAKE_MLX) clean
			@echo "${YELLOW}> All objects files of so_long have been deleted ❌${END}"

fclean:		clean
			@$(RM) $(NAME)
			@$(MAKE_LIBFT) fclean
			@$(MAKE_MLX) clean
			@echo "${YELLOW}> Cleaning of so_long has been done ❌${END}"

re:			fclean all

libft:
			@$(MAKE_LIBFT) all bonus

mlx:
			@$(MAKE_MLX)

.PHONY: all clean fclean re libft