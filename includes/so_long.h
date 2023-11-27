/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:43:05 by lquehec           #+#    #+#             */
/*   Updated: 2023/11/27 19:54:45 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// LIB
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

# define KEY_ESC			65307
# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_ARROW_TOP		65362
# define KEY_ARROW_BOT		65364
# define KEY_ARROW_LEFT		65361
# define KEY_ARROW_RIGHT	65363

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_image {
	void		*img;
	char		*addr;
	t_vector	size;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_image;

// ASSETS
typedef struct s_char
{
	t_image		*sprite;
	int			direction;
}	t_char;

typedef struct s_game
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	int			total_moves;
	void		*textures[5]; // MLX image pointers (on the stack)
	t_char		*player;
}	t_game;



#endif