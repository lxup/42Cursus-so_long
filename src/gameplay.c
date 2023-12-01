/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:54:08 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/01 20:08:26 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move(t_game *game, int y, int x, int direction)
{
	int	prev_x;
	int	prev_y;

	prev_x = game->player->position.x;
	prev_y = game->player->position.y;
	game->player->direction = direction;
	if (game->map->items[y][x] == EXIT && game->map->c_count == 0)
		ft_exit(game, SUCCESS, NULL);
	else if (is_valid_move(game, game->map->items, x, y) \
		&& game->map->items[y][x] != EXIT)
	{
		game->map->items[prev_y][prev_x] = FLOOR;
		if (game->map->items[y][x] == COINS)
			game->map->c_count--;
		game->player->position.x = x;
		game->player->position.y = y;
		game->map->items[y][x] = PLAYER;
		game->player->moves_count++;
		render(game);
	}	
}

int	on_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_ARROW_TOP)
		player_move(game, game->player->position.y - 1, \
			game->player->position.x, DIRECTION_TOP);
	if (keycode == KEY_S || keycode == KEY_ARROW_BOT)
		player_move(game, game->player->position.y + 1, \
			game->player->position.x, DIRECTION_BOT);
	if (keycode == KEY_A || keycode == KEY_ARROW_LEFT)
		player_move(game, game->player->position.y, \
		game->player->position.x - 1, DIRECTION_BOT);
	if (keycode == KEY_D || keycode == KEY_ARROW_RIGHT)
		player_move(game, game->player->position.y, \
		game->player->position.x + 1, DIRECTION_RIGHT);
	if (keycode == KEY_Q || keycode == KEY_ESC)
		return (*(int *)ft_exit(game, SUCCESS, NULL));
	return (0);
}
