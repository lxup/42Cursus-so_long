/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:33:10 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/05 15:03:10 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_elem(t_game *game, char c, int pos[2])
{
	if (ft_is_on_contour(game, pos) && c != '1')
		ft_exit(game, MAP_ERR, "not surrounded by wall");
	if (c == 'E')
		game->map->e_count++;
	else if (c == 'P')
	{
		game->player->position.y = pos[0];
		game->player->position.x = pos[1];
		game->map->spawn.y = pos[0];
		game->map->spawn.x = pos[1];
		game->map->p_count++;
	}
	else if (c == 'C')
		game->map->c_count++;
	else if (c == 'K')
		game->map->k_count++;
	else if (c == 'W')
		game->map->w_count++;
	else if (c != '1' && c != '0')
		ft_exit(game, MAP_ERR, "Invalid character, use only E, P, C, 1, 0, K");
}

int	ft_map_path_finder(t_game *game, t_map *map, int x, int y)
{
	int	i;

	i = -1;
	if (!is_valid_move(game, map->items, x, y))
		return (0);
	if (map->items[y][x] == 'E')
		map->e_count++;
	if (map->items[y][x] == 'C')
		map->c_count++;
	if (map->items[y][x] == 'W')
		map->w_count++;
	if (map->c_count == game->map->c_count \
		&& map->e_count == game->map->e_count)
		return (1);
	map->items[y][x] = 'V';
	while (++i < 4)
		if (ft_map_path_finder(game, map, \
			x + game->moves[i][1], y + game->moves[i][0]))
			return (1);
	return (0);
}

void	ft_check_map_solvability(t_game *game)
{
	t_map	map_check;

	map_check.size = game->map->size;
	map_check.fd = 0;
	map_check.spawn = game->map->spawn;
	map_check.items = ft_copy_matrix(game->map->items);
	map_check.e_count = 0;
	map_check.p_count = 0;
	map_check.c_count = 0;
	map_check.k_count = 0;
	map_check.w_count = 0;
	if (!map_check.items)
		ft_exit(game, MEMORY_ERR, NULL);
	if (!ft_map_path_finder(game, &map_check, game->player->position.x,
			game->player->position.y))
	{
		ft_free_matrix(map_check.items);
		ft_exit(game, MAP_ERR, "Map is not solvable.");
	}
	ft_free_matrix(map_check.items);
}

void	ft_check_map(t_game *game)
{
	int			pos[2];

	pos[0] = 0;
	while (game->map->items[pos[0]])
	{
		pos[1] = 0;
		while (game->map->items[pos[0]][pos[1]])
		{
			ft_check_map_elem(game, game->map->items[pos[0]][pos[1]], pos);
			pos[1]++;
		}
		if (pos[1] != game->map->size->x)
			ft_exit(game, MAP_ERR, "Its has to be a rectangle, DAMN !");
		pos[0]++;
	}
	if (game->map->e_count != 1
		|| game->map->p_count != 1
		|| game->map->c_count < 1)
		ft_exit(game, MAP_ERR, "Invalid map settings number.");
	ft_check_map_solvability(game);
}
