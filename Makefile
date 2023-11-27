# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 17:38:15 by lquehec           #+#    #+#              #
#    Updated: 2023/11/27 18:17:03 by lquehec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	= ./src/
HEADER_DIR	= ./includes/
MLX_DIR =  ./mlx/

SRCS 		= $(addprefix $(SRCS_DIR),\
				main.c)

OBJS		= $(SRCS:.c=.o)

CC			= cc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

INCLUDES = -I/usr/include -Imlx
MAKE_MLX	= make -C $(MLX_DIR)
MLX_A		= $(MLX_DIR)libmlx.a
# MLX_FLAGS	= -lmlx -lXext -lX11
MLX_FLAGS	= -I -g3 -L /usr/X11/lib -Lincludes -L./mlx -lmlx -Imlx -lXext -lX11 -lz -lm

NAME		= so_long

.c.o:
			$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(MAKE_MLX)
			$(CC) $(CFLAGS) $(MLX_FLAGS) -I $(HEADER_DIR) $(OBJS) $(MLX_A) -o $(NAME)

all: 		$(MLX_LIB) $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re