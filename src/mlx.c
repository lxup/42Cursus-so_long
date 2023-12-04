/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:18:03 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/04 11:48:03 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	ft_new_sprite(char *path, t_game *game)
{
	t_image	sprite;

	sprite.img = mlx_xpm_file_to_image(game->mlx_ptr, path, \
		&sprite.size.x, &sprite.size.y);
	if (sprite.img == NULL)
		ft_exit(game, SPRITE_NEW_ERR, path);
	sprite.addr = mlx_get_data_addr(sprite.img, \
		&sprite.bits_per_pixel, &sprite.size_line, &sprite.endian);
	return (sprite);
}

void	ft_init_sprites(t_game *game)
{
	game->textures->wall = ft_new_sprite(WALL_XPM, game);
	game->textures->floor = ft_new_sprite(FLOOR_XPM, game);
	game->textures->coins = ft_new_sprite(COINS_XPM, game);
	game->textures->exit_open = ft_new_sprite(EXIT_OPEN_XPM, game);
	game->textures->exit_closed = ft_new_sprite(EXIT_CLOSED_XPM, game);
	game->textures->heart_full = ft_new_sprite(HEART_FULL_XPM, game);
	game->textures->heart_empty = ft_new_sprite(HEART_EMPTY_XPM, game);
	game->player->sprite_front = ft_new_sprite(PLAYER_FRONT_XPM, game);
	game->player->sprite_back = ft_new_sprite(PLAYER_BACK_XPM, game);
	game->player->sprite_left = ft_new_sprite(PLAYER_LEFT_XPM, game);
	game->player->sprite_right = ft_new_sprite(PLAYER_RIGHT_XPM, game);
}

void	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		ft_exit(game, MLX_INIT_ERR, NULL);
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
		game->map->size->x * IMG_WIDTH, \
		game->map->size->y * IMG_HEIGHT, WINDOW_TITLE);
	if (game->win_ptr == NULL)
		ft_exit(game, MLX_NEW_WINDOW_ERR, NULL);
}
