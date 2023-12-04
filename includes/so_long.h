/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:43:05 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/04 21:07:19 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// LIB
# ifdef __APPLE__
#  include "../mlx-opengl/mlx.h"
#  define OS "macos"
# elif __linux__
#  include "../mlx-linux/mlx.h"
#  define OS "linux"
# endif
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

/* ==================== PROJECT SETTINGS ====================*/
# define FILE_EXTENSION 	".ber"
# define WINDOW_TITLE 		"so_long"

// GAMEPLAY
# define LIFE_COUNT			1

// INTERFACE
# define INTERFACE_SIZE		100

// SOURCES
# define WALL_XPM 			"./assets/water/water_1.xpm"
# define FLOOR_XPM 			"./assets/floor/floor_1.xpm"
# define COINS_XPM 			"./assets/coins/coin_w_bg_00.xpm"
# define EXIT_OPEN_XPM 		"./assets/exit/exit_open.xpm"
# define EXIT_CLOSED_XPM 	"./assets/exit/exit_closed.xpm"

# define HEART_FULL_XPM 	"./assets/heart/heart_full.xpm"
# define HEART_EMPTY_XPM 	"./assets/heart/heart_empty.xpm"

# define PLAYER_FRONT_XPM 	"./assets/chars/fox/fox_front_idle_w_bg_00.xpm"
# define PLAYER_BACK_XPM 	"./assets/chars/fox/fox_back_idle_w_bg_00.xpm"
# define PLAYER_LEFT_XPM 	"./assets/chars/fox/fox_left_idle_w_bg_00.xpm"
# define PLAYER_RIGHT_XPM 	"./assets/chars/fox/fox_right_idle_w_bg_00.xpm"

# define ENEMY_FRONT_XPM 	"./assets/chars/crab/crab_front_idle_w_bg_00.xpm"

# define WEAPON_AXE_XPM 	"./assets/weapons/axe/axe_w_bg_00.xpm"

// MAP SETTINGS
# define WALL 				'1'
# define FLOOR 				'0'
# define COINS 				'C'
# define PLAYER 			'P'
# define EXIT 				'E'
# define ENEMY 				'K'
# define WEAPON 			'W'

// DIRECTIONS
# define DIRECTION_TOP		1
# define DIRECTION_BOT		2
# define DIRECTION_LEFT		3
# define DIRECTION_RIGHT	4

// KEYS
# ifdef __APPLE__
#  define KEY_ESC			53
#  define KEY_Q				12
#  define KEY_W				13
#  define KEY_E				14
#  define KEY_A				0
#  define KEY_S				1
#  define KEY_D				2
#  define KEY_ARROW_TOP		126
#  define KEY_ARROW_BOT		125
#  define KEY_ARROW_LEFT	123
#  define KEY_ARROW_RIGHT	124
# elif __linux__
#  define KEY_ESC			65307
#  define KEY_Q				113
#  define KEY_W				119
#  define KEY_E				101
#  define KEY_A				97
#  define KEY_S				115
#  define KEY_D				100
#  define KEY_ARROW_TOP		65362
#  define KEY_ARROW_BOT		65364
#  define KEY_ARROW_LEFT	65361
#  define KEY_ARROW_RIGHT	65363
# endif

# define IMG_WIDTH			32
# define IMG_HEIGHT			32
/* ==================== PROJECT SETTINGS ====================*/

// Gameplay msg
enum			e_msg
{
	SUCCESS				= 1,
	LOOSE				= 2,
	LEAVE				= 3,
};

// Error handling
enum			e_errors
{
	MEMORY_ERR			= -10,
	ARGS_ERR			= -11,
	FILE_ERR			= -12,
	MAP_ERR				= -20,
	MLX_INIT_ERR		= -30,
	SPRITE_NEW_ERR		= -31,
	MLX_NEW_WINDOW_ERR	= -40,
};

typedef struct s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef struct s_image
{
	void		*img;
	char		*addr;
	t_vector	size;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_image;

// ASSETS
typedef struct s_char
{
	t_image		sprite_front;
	t_image		sprite_back;
	t_image		sprite_left;
	t_image		sprite_right;
	int			direction;
	t_vector	position;
	int			moves_count;
	int			life;
	int			weapon_count;
}				t_char;

typedef struct s_map
{
	t_vector	*size;
	int			fd;
	char		**items;
	int			e_count;
	int			p_count;
	int			c_count;
	int			k_count;
	int			w_count;
	t_vector	spawn;
}				t_map;

typedef struct s_textures
{
	t_image		wall;
	t_image		floor;
	t_image		coins;
	t_image		exit_open;
	t_image		exit_closed;
	t_image		heart_full;
	t_image		heart_empty;
	t_image		enemy;
	t_image		weapon;
}				t_textures;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int			width;
}				t_win;

typedef struct s_game
{
	t_win		win;
	t_map		*map;
	t_char		*player;
	t_textures	*textures;
	int			moves[4][2];
}				t_game;

// MAIN
void			hook_register(t_game *game);
int				on_window_close(t_game *game);

// INIT
t_game			*ft_init(void);
t_game			*ft_init_game(void);
t_map			*ft_init_map(t_game *game);

// MLX
void			ft_init_mlx(t_game *game);
void			ft_init_sprites(t_game *game);
t_image			ft_new_sprite(char *path, t_game *game);

// EXIT
void			*ft_exit(t_game *game, int error, char *param);

// ERROR
void			ft_error(int error, char *param);

// FREE
void			ft_free_game(t_game *game);
void			ft_free_map(t_map *map);

// MAP_GET
void			ft_get_map(t_game *game, char *map_path);

// MAP_CHECK
void			ft_check_map(t_game *game);

// RENDER
int				render(t_game *game);
void			ft_render_sprite(t_game *game, t_image sprite, int line,
					int column);
void			ft_render_player(t_game *game, int y, int x);

// RENDER_FLOOR
void			ft_render_floor(t_game *game, int y, int x);

// RENDER_INTERFACE
void			ft_render_interface(t_game *game);

// GAMEPLAY
void			player_move(t_game *game, int y, int x, int direction);
void			on_enemy_move(t_game *game, int y, int x);
t_vector		get_attack_pos(t_game *game);
void			player_attack(t_game *game);
int				on_keypress(int keycode, t_game *game);

// MAP_UTILS
int				is_valid_move(t_game *game, char **map, int x, int y);
int				ft_is_on_contour(t_game *game, int pos[2]);

// TOOLS
int				ft_get_matrix_size(char **matrix);
char			**ft_copy_matrix(char **matrix);
void			ft_free_matrix(char **matrix);
void			ft_free_matrix_with_indice(char **matrix, int i);
void			ft_matrixprint(char **matrix);

#endif