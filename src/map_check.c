/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:33:10 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/05 20:39:14 by lquehec          ###   ########.fr       */
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

int	ft_map_path_finder(t_game *game, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map->size->y)
	{
		x = 0;
		while (x < game->map->size->x && map[y][x])
		{
			if (map[y][x] == 'E' || map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_fulfill(t_game *game, char **map, int x, int y)
{
	int	i;

	i = -1;
	if (x < 0 || y < 0 || x >= game->map->size->x || y >= game->map->size->y)
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (0);
	if (map[y][x] == 'E')
	{
		map[y][x] = 'V';
		return (0);
	}
	map[y][x] = 'V';
	while (++i < 4)
		if (ft_fulfill(game, map, \
			x + game->moves[i][1], y + game->moves[i][0]))
			return (1);
	return (0);
}

void	ft_check_map_solvability(t_game *game)
{
	char	**map;

	map = ft_copy_matrix(game->map->items);
	if (!map)
		ft_exit(game, MEMORY_ERR, NULL);
	ft_fulfill(game, map, game->player->position.x, game->player->position.y);
	if (!ft_map_path_finder(game, map))
	{
		ft_free_matrix(map);
		ft_exit(game, MAP_ERR, "Map is not solvable.");
	}
	ft_free_matrix(map);
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
	if (game->map->e_count != 1)
		ft_exit(game, MAP_ERR, "Need to have only one Exit (E)");
	if (game->map->p_count != 1)
		ft_exit(game, MAP_ERR, "Need to have only one Spawn (P)");
	if (game->map->c_count < 1)
		ft_exit(game, MAP_ERR, "Need to have at least one collectible (C)");
	if (game->map->k_count && !game->map->w_count)
		ft_exit(game, MAP_ERR, "if there is enemy u need a weapon (W)");
	ft_check_map_solvability(game);
}
