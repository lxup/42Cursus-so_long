/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:43:05 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/01 13:55:57 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// LIB
# ifdef __APPLE__
# 	include <OpenGL/gl.h>
#	include <mlx.h>
// #   include "../mlx_opengl/mlx.h"
// #   include "../mlx_opengl/mlx_int.h"
# else
#   include "../mlx/mlx.h"
// #   include "../mlx/mlx_int.h"
# endif
// # include "../mlx/mlx.h"
// # include "../mlx/mlx_int.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

// A DELETTTTEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
# include <stdio.h>

// PROJECT
# define FILE_EXTENSION		".ber"

# define KEY_ESC			65307
# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_ARROW_TOP		65362
# define KEY_ARROW_BOT		65364
# define KEY_ARROW_LEFT		65361
# define KEY_ARROW_RIGHT	65363

// Error handling
enum e_errors
{
	SUCCESS = 1,
	// CASUAL ERROR BEGIN AT -10
	MEMORY_ERR = -10,
	ARGS_ERR = -11,
	FILE_ERR = -12,
	// MAP ERROR BEGIN AT -20
	MAP_ERR = -20,
};

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
	int			size_line;
	int			endian;
}	t_image;

// ASSETS
typedef struct s_char
{
	t_image		*sprite;
	int			direction;
	t_vector	*position;
}	t_char;

typedef struct s_map
{
	t_vector			*size;
	int					fd;
	// t_list				*items;
	char				**items;
	int					e_count;
	int					p_count;
	int					c_count;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	t_map		*map;
	// void		*textures[5]; // MLX image pointers (on the stack)
	t_char		*player;
	int			total_moves;
}	t_game;

// INIT
t_game	*ft_init(void);
t_game	*ft_init_game(void);
t_map	*ft_init_map(t_game *game);

// EXIT
void	*ft_exit(t_game *game, int error, char *param);

// ERROR
void	ft_error(int error, char *param);

// FREE
void	ft_free_game(t_game *game);
void	ft_free_map(t_map *map);
void	ft_free_matrix(char ***matrix);
void	ft_free_matrix_with_indice(char **matrix, int i);

// MAP_GET
void	ft_get_map(t_game *game, char *map_path);

// MAP_CHECK
void	ft_check_map(t_game *game);

// MAP_UTILS
int		is_valid_move(t_game *game, char **map, int x, int y);
int		ft_is_on_contour(t_game *game, int pos[2]);

// TOOLS
int		ft_get_matrix_size(char **matrix);
char	**ft_copy_matrix(char **matrix);
void	ft_lstprint(t_list *lst);
void	ft_matrixprint(char **matrix);


#endif