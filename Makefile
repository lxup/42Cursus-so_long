# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 17:38:15 by lquehec           #+#    #+#              #
#    Updated: 2023/11/30 21:32:34 by lquehec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	= ./src/
HEADER_DIR	= ./includes/
MLX_DIR =  ./mlx/
LIBFT_DIR	= ./libft/

SRCS 		= $(addprefix $(SRCS_DIR),\
				main.c \
				init.c \
				exit.c \
				error.c \
				free.c \
				map.c )

OBJS		= $(SRCS:.c=.o)

CC			= cc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

# LIBRARY
INCLUDES = -I/usr/include -Imlx
MAKE_MLX	= make -C $(MLX_DIR)
MLX_A		= $(MLX_DIR)libmlx.a
MLX_FLAGS	= -I -g3 -L /usr/X11/lib -Lincludes -L./mlx -lmlx -Imlx -lXext -lX11 -lz -lm
# LIBFT
MAKE_LIBFT	= make -s -C $(LIBFT_DIR)
LIBFT_A		= $(LIBFT_DIR)libft.a

NAME		= so_long

.c.o:
			$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(MAKE_LIBFT) all bonus
			$(MAKE_MLX)
			$(CC) $(CFLAGS) $(MLX_FLAGS) -I $(HEADER_DIR) $(OBJS) $(LIBFT_A) $(MLX_A) -o $(NAME)

all: 		$(NAME)

clean:
			$(RM) $(OBJS)
			$(MAKE_LIBFT) clean
			# $(MAKE_MLX) clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE_LIBFT) fclean
			# $(MAKE_MLX) fclean

re:			fclean all

.PHONY: all clean fclean re