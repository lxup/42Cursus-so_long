/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:01:41 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/04 11:42:14 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_sprite(t_game *game, t_image sprite, int line, int column)
{
	mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
	sprite.img, column * sprite.size.x, line * sprite.size.y);
}

void	ft_get_sprite(t_game *game, int y, int x)
{
	char	value;

	value = game->map->items[y][x];
	if (value == WALL)
		ft_render_sprite(game, game->textures->wall, y, x);
	else if (value == FLOOR)
		ft_render_floor(game, y, x);
	else if (value == COINS)
	{
		ft_render_floor(game, y, x);
		ft_render_sprite(game, game->textures->coins, y, x);
	}
	else if (value == EXIT)
	{
		if (game->map->c_count == 0)
			ft_render_sprite (game, game->textures->exit_open, y, x);
		else
			ft_render_sprite (game, game->textures->exit_closed, y, x);
	}
	else if (value == PLAYER)
		ft_render_player(game, y, x);
}

void	ft_render_player(t_game *game, int y, int x)
{
	ft_render_sprite(game, game->textures->floor, y, x);
	if (game->player->direction == DIRECTION_BOT)
		ft_render_sprite (game, game->player->sprite_front, y, x);
	if (game->player->direction == DIRECTION_TOP)
		ft_render_sprite (game, game->player->sprite_back, y, x);
	if (game->player->direction == DIRECTION_LEFT)
		ft_render_sprite (game, game->player->sprite_left, y, x);
	if (game->player->direction == DIRECTION_RIGHT)
		ft_render_sprite (game, game->player->sprite_right, y, x);
}

int	render(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->size->y)
	{
		x = 0;
		while (x < game->map->size->x)
		{
			ft_get_sprite(game, y, x);
			x++;
		}
		y++;
	}
	ft_render_interface(game);
	return (0);
}
