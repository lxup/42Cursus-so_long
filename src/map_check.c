/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:33:10 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/01 14:04:04 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_elem(t_game *game, char c, int pos[2])
{
	if (ft_is_on_contour(game, pos) && c != '1')
		ft_exit(game, MAP_ERR, "Not only wall in border");
	if (c == 'E')
		game->map->e_count++;
	else if (c == 'P')
	{
		game->player->position->y = pos[0];
		game->player->position->x = pos[1];
		game->map->p_count++;
	}
	else if (c == 'C')
		game->map->c_count++;
	else if (c != '1' && c != '0')
		ft_exit(game, MAP_ERR, "Invalid character, use only E, P, C, 1, 0");
}

int	ft_map_path_finder(t_game *game, char **map, int x, int y)
{
	int	i;

	if (!is_valid_move(game, map, x, y))
		return (0);
	if (map[y][x] == 'E')
		return (1);
	map[y][x] = 'V';
	i = -1;
	int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	while (++i < 4)
	{
		if (ft_map_path_finder(game, map, x + moves[i][1], y + moves[i][0]))
			return (1);
	}
	return (0);
}

void	ft_check_map_solvability(t_game *game)
{
	char	**map;

	map = ft_copy_matrix(game->map->items);
	if (!map)
		ft_exit(game, MEMORY_ERR, NULL);
	if (!ft_map_path_finder(game, map, game->player->position->x,
			game->player->position->y))
	{
		ft_free_matrix(&map);
		ft_exit(game, MAP_ERR, "Map is not solvable.");
	}
	ft_free_matrix(&map);
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
			ft_exit(game, MAP_ERR, "All row need to have the same size.");
		pos[0]++;
	}
	if (game->map->e_count != 1
		|| game->map->p_count != 1
		|| game->map->c_count < 1)
		ft_exit(game, MAP_ERR, "Invalid map settings number.");
	ft_check_map_solvability(game);
}
