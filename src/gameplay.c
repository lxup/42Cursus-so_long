/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:54:08 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/04 20:46:38 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	on_enemy_move(t_game *game, int y, int x)
{
	t_vector	apos;
	int			prev_x;
	int			prev_y;

	prev_x = game->player->position.x;
	prev_y = game->player->position.y;
	apos = get_attack_pos(game);
	if (apos.y != y || apos.x != x)
		return ;
	else if (game->player->life == 1)
		ft_exit(game, LOOSE, NULL);
	else
	{
		game->map->items[prev_y][prev_x] = FLOOR;
		game->player->position.x = game->map->spawn.x;
		game->player->position.y = game->map->spawn.y;
		game->map->items[game->map->spawn.y][game->map->spawn.x] = PLAYER;
		game->player->moves_count++;
	}
	game->player->life--;
}

void	player_move(t_game *game, int y, int x, int direction)
{
	int	prev_x;
	int	prev_y;

	prev_x = game->player->position.x;
	prev_y = game->player->position.y;
	if (game->map->items[y][x] == EXIT && game->map->c_count == 0)
		ft_exit(game, SUCCESS, NULL);
	else if (game->map->items[y][x] == ENEMY)
		on_enemy_move(game, y, x);
	else if (is_valid_move(game, game->map->items, x, y) \
		&& game->map->items[y][x] != EXIT)
	{
		game->map->items[prev_y][prev_x] = FLOOR;
		if (game->map->items[y][x] == WEAPON)
			game->player->weapon_count++;
		if (game->map->items[y][x] == COINS)
			game->map->c_count--;
		game->player->position.x = x;
		game->player->position.y = y;
		game->map->items[y][x] = PLAYER;
		game->player->moves_count++;
	}
	game->player->direction = direction;
	if (ft_strncmp(OS, "linux", 5) == 0)
		render(game);
}

t_vector	get_attack_pos(t_game *game)
{
	t_vector	attack_pos;

	attack_pos.x = 0;
	attack_pos.y = 0;
	if (game->player->direction == DIRECTION_TOP)
	{
		attack_pos.x = game->player->position.x;
		attack_pos.y = game->player->position.y - 1;
	}
	else if (game->player->direction == DIRECTION_BOT)
	{
		attack_pos.x = game->player->position.x;
		attack_pos.y = game->player->position.y + 1;
	}
	else if (game->player->direction == DIRECTION_LEFT)
	{
		attack_pos.x = game->player->position.x - 1;
		attack_pos.y = game->player->position.y;
	}
	else if (game->player->direction == DIRECTION_RIGHT)
	{
		attack_pos.x = game->player->position.x + 1;
		attack_pos.y = game->player->position.y;
	}
	return (attack_pos);
}

void	player_attack(t_game *game)
{
	t_vector	apos;

	if (!game->player->weapon_count)
		return ;
	apos = get_attack_pos(game);
	if (game->map->items[apos.y][apos.x] == ENEMY)
		game->map->items[apos.y][apos.x] = FLOOR;
	if (ft_strncmp(OS, "linux", 5) == 0)
		render(game);
	game->player->moves_count++;
}

int	on_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_E)
		player_attack(game);
	if (keycode == KEY_W || keycode == KEY_ARROW_TOP)
		player_move(game, game->player->position.y - 1, \
			game->player->position.x, DIRECTION_TOP);
	if (keycode == KEY_S || keycode == KEY_ARROW_BOT)
		player_move(game, game->player->position.y + 1, \
			game->player->position.x, DIRECTION_BOT);
	if (keycode == KEY_A || keycode == KEY_ARROW_LEFT)
		player_move(game, game->player->position.y, \
		game->player->position.x - 1, DIRECTION_LEFT);
	if (keycode == KEY_D || keycode == KEY_ARROW_RIGHT)
		player_move(game, game->player->position.y, \
		game->player->position.x + 1, DIRECTION_RIGHT);
	if (keycode == KEY_Q || keycode == KEY_ESC)
		return (*(int *)ft_exit(game, SUCCESS, NULL));
	return (0);
}
